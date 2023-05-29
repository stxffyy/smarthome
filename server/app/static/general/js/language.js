
function changeLanguage(code) {
    console.log(code);
    document.getElementsByName("language")[0].value = code;
    console.log(document.getElementById('lang'));
    document.getElementById('lang').submit();
}

function showLanguages() {
    document.getElementById("languagesId").classList.toggle("show");
}

window.onclick = function(event) {
    if (!event.target.matches('.selected-lang')) {

        const dropdowns = document.getElementsByClassName("languages");
        let i;
        for (i = 0; i < dropdowns.length; i++) {
            const openDropdown = dropdowns[i];
            if (openDropdown.classList.contains('show')) {
                openDropdown.classList.remove('show');
            }
        }
    }
}
