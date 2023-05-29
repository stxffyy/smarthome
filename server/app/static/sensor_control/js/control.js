let out_executor;

let card = document.getElementById('Display');
const canvas = document.getElementById("canvas");
canvas.width = "320";
canvas.height = "240";
const ctx = canvas.getContext("2d");
ctx.font = "16px arial";

let painting = false;
let sX, sY, fX, fY;
let textXY;
let prevCanvas;
let mode = "line";
let xPs = [];
let yPs = [];
let output = [];
let rangeValue = 50;
let color = 0;
let colors = ['black', 'white', 'red', 'green', 'blue', 'brown', 'yellow', 'grey']
let size = 0;

output  = display_data;

let out_executors = [];

for (const fig of display_data) {
    let vals = fig['values'];
    ctx.beginPath();
    switch (fig['arg']) {
        case 'line':
            ctx.strokeStyle = colors[parseInt(vals[4])];
            ctx.fillStyle = colors[parseInt(vals[4])];
            ctx.moveTo(vals[0], vals[1]);
            ctx.lineTo(vals[2], vals[3]);
            break;
        case 'rectangle':
            ctx.strokeStyle = colors[parseInt(vals[4])];
            ctx.fillStyle = colors[parseInt(vals[4])];
            ctx.rect(vals[0], vals[1], vals[2] - vals[0], vals[3] - vals[1]);
            break;
        case 'filledRectangle':
            ctx.strokeStyle = colors[parseInt(vals[4])];
            ctx.fillStyle = colors[parseInt(vals[4])];
            ctx.fillRect(vals[0], vals[1], vals[2] - vals[0], vals[3] - vals[1]);
            break;
        case 'circle':
            ctx.strokeStyle = colors[parseInt(vals[3])];
            ctx.fillStyle = colors[parseInt(vals[3])];
            ctx.arc(vals[0], vals[1], vals[2], 0, 2 * Math.PI);
            break;
        case 'text':
            ctx.strokeStyle = colors[parseInt(vals[3])];
            ctx.fillStyle = colors[parseInt(vals[3])];
            ctx.textBaseline = 'top';
            ctx.textAlign = 'left';
            let x, y;
            x = parseInt(vals[0]) + canvas.getBoundingClientRect().left - card.getBoundingClientRect().left;
            y = parseInt(vals[1]) + canvas.getBoundingClientRect().top - card.getBoundingClientRect().top;
            printLines(vals[4], parseInt(vals[0]), parseInt(vals[1]),
                (Math.floor(323 - parseInt(vals[0])) + 'px'), (parseInt(vals[2]) * 8 + 16));
            break;
    }
    ctx.stroke();
    ctx.closePath();
}

function setColor(id, c) {
    switch (c) {
        case 'black':
            color = 0;
            break;
        case 'white':
            color = 1;
            break;
        case 'red':
            color = 2;
            break;
        case 'green':
            color = 3;
            break;
        case 'blue':
            color = 4;
            break;
        case 'brown':
            color = 5;
            break;
        case 'yellow':
            color = 6;
            break;
        case 'grey':
            color = 7;
            break;
    };
    const ids = ['d_c_black', 'd_c_white', 'd_c_red', 'd_c_green', 'd_c_blue', 'd_c_brown', 'd_c_yellow', 'd_c_grey'];
    const btn_c = document.getElementById(id);
    if (btn_c.style.borderColor === 'rgb(33, 45, 99)') {
        btn_c.style.borderColor = 'rgb(84, 105, 212)';
    } else {
        for (let id_btn of ids) {
            document.getElementById(id_btn).style.borderColor = 'rgb(84, 105, 212)';
        }
        btn_c.style.borderColor = c;
    }
    ctx.strokeStyle = c;
    ctx.fillStyle = c;
}

function changeFont(s) {
    size = Math.floor((parseInt(s) - 16) / 8);
    ctx.font = s + 'px ' + 'arial';
}

function startPosition(e) {

    painting = true;
    sX = e.clientX - canvas.getBoundingClientRect().left;
    sY = e.clientY - canvas.getBoundingClientRect().top;
    appendElements(sX, sY);
    prevCanvas = ctx.getImageData(0, 0, canvas.width, canvas.height);
    draw(e);
}

function finishPosition() {
    if (!painting) return;
    painting = false;
    ctx.closePath();
    appendElements(fX, fY);
    switch (mode) {
        case "line":
        case "rectangle":
        case "filledRectangle":
            output.push({
                "arg": mode,
                "values": [
                    Math.floor(xPs[0]),
                    Math.floor(yPs[0]),
                    Math.floor(xPs[1]),
                    Math.floor(yPs[1]),
                    color
                ]
            });
            break;
        case "circle":
            output.push({
                "arg": mode,
                "values": [
                    Math.floor(xPs[0]),
                    Math.floor(yPs[0]),
                    Math.floor(Math.sqrt((xPs[1] - xPs[0]) ** 2 + (yPs[1] - yPs[0]) ** 2)),
                    color
                ]
            });
            break;
        default:
            break;
    }
}

function draw(e) {
    if (!painting) return;
    e.preventDefault();
    e.stopPropagation();

    fX = e.clientX - canvas.getBoundingClientRect().left;
    fY = e.clientY - canvas.getBoundingClientRect().top;
    ctx.putImageData(prevCanvas, 0, 0);
    ctx.beginPath();
    switch (mode) {
        case "line":
            ctx.moveTo(sX, sY);
            ctx.lineTo(fX, fY);
            break;
        case "rectangle":
            ctx.rect(sX, sY, fX - sX, fY - sY);
            break;
        case "filledRectangle":
            ctx.fillRect(sX, sY, fX - sX, fY - sY);
            break;
        case "circle":
            ctx.arc(sX, sY, Math.sqrt((fX - sX) ** 2 + (fY - sY) ** 2), 0, 2 * Math.PI);
            break;
        case "text":
            printText(e, fX, fY);
            painting = false;
            break;
    }
    ctx.stroke();
}

canvas.addEventListener("mousedown", startPosition, false);
canvas.addEventListener("mouseup", finishPosition, false);
canvas.addEventListener("mousemove", draw, false);

canvas.addEventListener("touchmove", function (e) {
    let touch = e.touches[0];
    let mouseEvent = new MouseEvent("mousemove", {
        clientX: touch.clientX,
        clientY: touch.clientY
  });
  canvas.dispatchEvent(mouseEvent);
}, false);

canvas.addEventListener("touchstart", function (e) {
    let touch = e.touches[0];
    let mouseEvent = new MouseEvent("mousedown", {
        clientX: touch.clientX,
        clientY: touch.clientY
  });
  canvas.dispatchEvent(mouseEvent);
}, false);

canvas.addEventListener("touchend", function (e) {
    let touch = e.changedTouches[0];
    let mouseEvent = new MouseEvent("mouseup", {
        clientX: touch.clientX,
        clientY: touch.clientY
  });
  canvas.dispatchEvent(mouseEvent);
}, false);

function clearCanvas() {
    let inputs = card.getElementsByClassName('input-display-input');
    while (inputs[0]) {
        inputs[0].parentNode.removeChild(inputs[0]);
    }
    ctx.clearRect(0, 0, 320, 240);
    output = [];
}

function setMode(id, name) {
    const ids = ['d_m_line', 'd_m_rect', 'd_m_fillRect', 'd_m_circle', 'd_m_text', 'd_m_clear'];
    const btn_m = document.getElementById(id);
    if (btn_m.style.backgroundColor === 'rgb(33, 45, 99)') {
        btn_m.style.backgroundColor = 'rgb(84, 105, 212)';
    } else {
        for (let id_btn of ids) {
            document.getElementById(id_btn).style.backgroundColor = 'rgb(84, 105, 212)';
        }
        btn_m.style.backgroundColor = 'rgb(33, 45, 99)';
    };
    mode = name;
}

function printText(e, x, y) {
    let input = document.createElement('textarea');
    input.className = 'input-display-input';
    input.type = 'text';
    input.style.position = 'absolute';
    let xInput = x + canvas.getBoundingClientRect().left - card.getBoundingClientRect().left;
    input.style.left = xInput + 'px';
    input.style.top = (y + canvas.getBoundingClientRect().top - card.getBoundingClientRect().top) + 'px';
    input.style.width = Math.floor(323 - x) + 'px';
    input.style.resize = 'none';
    input.oninput = resizeOnPrinting;
    input.style.border = 'none';
    input.style.outline = 'none';
    input.style.color = ctx.strokeStyle;
    input.style.font = (size * 8 + 16) + 'px arial';
    input.style.zIndex = '99';
    input.onkeyup = handleEnter;

    card.appendChild(input);

    input.focus();
}

function resizeOnPrinting(e) {
    this.style.height = this.scrollHeight + 'px';
}

function printLines(text, leftInput, topInput, widthInput, fontSizeInput) {
    let line = '';
    let lineWidth = 0;
    let y = parseInt((topInput - canvas.getBoundingClientRect().top).toString(), 10);
    for (let i = 0; i < text.length; i++) {
        if (lineWidth + ctx.measureText(text[i]).width >= parseInt(widthInput, 10) ) {
            ctx.fillText(
                line,
                parseInt((leftInput - canvas.getBoundingClientRect().left).toString(), 10), y);
            y += parseInt(fontSizeInput, 10);
            line = text[i];
            lineWidth = ctx.measureText(text[i]).width;
        } else {
            lineWidth += ctx.measureText(text[i]).width;
            line += text[i];
        }
    }
    if (line !== '') {
        ctx.fillText(
            line,
            parseInt((leftInput - canvas.getBoundingClientRect().left).toString(), 10), y);
    }
}

function handleEnter(e) {
    if (e.keyCode === 13) {
        ctx.textBaseline = 'top';
        ctx.textAlign = 'left';
        textXY = this.value;

        printLines(textXY, this.getBoundingClientRect().left, this.getBoundingClientRect().top,
            this.style.width,
            this.style.fontSize);

        card.removeChild(this);

        output.push({
            "arg": mode,
            "values": [
                Math.floor(xPs[1]),
                Math.floor(yPs[1]),
                size,
                color,
                textXY
            ]
        });
    }
}

function appendElements(x, y) {
    if (x === xPs[xPs.length - 1] && y === yPs[yPs.length - 1]) return;
    if (xPs.length >= 2) xPs.shift();

    if (yPs.length >= 2) yPs.shift();

    xPs.push(x);
    yPs.push(y);

}

function sendDisplay() {
    // console.log('sendDisplay');
    // output.push();
    // //TODO: sendToBD
    // out_executor.push(output);
}

// --------------------------------------------------------------------------------------------------------------------
// TODO add for STOP_or_OFF button like a send button
let ranges1 = document.querySelectorAll('input[type=range]');

for (let i = 0; i < ranges1.length; i++) {
    ranges1[i].ontouchmove = rangeSlider;
}

function rangeSlider(id, value) {
    const value_id = id + '-range-value';
    document.getElementById(value_id).innerHTML = value;
}

let btns_send = document.querySelectorAll('[id^="button_send_"]');

for (let btn_send of btns_send) {
    btn_send.onclick = function() {
        let sub = btn_send.id.replace('button_send_', '');
        out_executor = {
            'type': sub.split('_')[0],
            'port': sub.split('_')[1],
            'value': []
        }
        if (sub.split('_')[0] === '26') {
            console.log(output);
            out_executor.value = output;
        } else if (sub.split('_')[0] === '27') {
            console.log('MP3');
        } else {
            out_executor.value.push({'arg': sub.split('_')[0], 'values': []})
            sub = '[id$=\"' + btn_send.id.replace('button_send_', '') + '\"]';
            let inps = document.querySelectorAll(sub);
            for (let inp of inps) {
                if (inp.type === 'checkbox') {
                    out_executor.value[0].values.push(inp.checked ? '1' : '0');
                } else if (inp.id.split('_')[1] !== 'send') {
                    out_executor.value[0].values.push(inp.value === '' ? '0' : inp.value);
                }
            }
        }
        out_executors.push(out_executor);
        store_executors(out_executor);
    };
}

// ------------------------------------------------------------------------------------------------------------------

function store_executors(data) {
    $.ajax({
        method: 'POST',
        url: url_store_executors,
        dataType: 'json',
        data:  {'user': 'LELKEK', 'data': JSON.stringify(data), 'is_auto': '0'},

        success: function () {
            console.log(data);
        },
        error: function () {
            // console.log("NOOOOOO");
        }
    });
}