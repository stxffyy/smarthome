import json
from django.utils.safestring import mark_safe


devices_with_groups = {
    'light_sensors': {
        'type': 'sensors',
        'devices': [[0, 1, 2], [3, 4, 5], 40]
    },
    'direct_interaction_sensors': {
        'type': 'sensors',
        'devices': [9, 8, 50, 51, 52, 53]
    },
    'physical_sensors': {
        'type': 'sensors',
        'devices': [17, 18, 20, 31, 32, 33, 34, 35, 36, 37, 38, 39]
    },
    'special_sensors': {
        'type': 'sensors',
        'devices': [67, 23, 16, 19]
    },
    'color_sensors': {
        'type': 'sensors',
        'devices': [42, 43, 44, 45, 46, 47, 48, 49, 21]
    },
    'time_sensors': {
        'type': 'sensors',
        'devices': [61, 62, 63, 64, 65, 66]
    },
    'environmental_sensors': {
        'type': 'sensors',
        'devices': [68, 54, 55, 56, 57]
    },
    'motor_executors': {
        'type': 'executors',
        'devices': [24, 25, 28, 29, 30]
    },
    'direct_impact_executors': {
        'type': 'executors',
        'devices': [6, 7, 10, 11, 12, 13, 14, 15, 26, 27, 58, 59, 60, 41]
    },
}


def get_manual_sensors(inits, sensors):
    manual_sensors = []
    for sensor in sensors:
        for init in inits:
            if init['type'] == sensor['port'] and init['type'] == sensor['port']:
                manual_sensors.append(sensor)
    return manual_sensors


def get_auto_inits(sensors):
    auto_inits = []
    for sensor in sensors:
        auto_inits.append({'type': sensor['type'], 'port': sensor['port']})
    return auto_inits

# def deserialize_data(json_data: dict, is_auto: bool, mode='data'):
#     context = dict()
#     data = json.loads(str(json_data))
#     devices = data['data']
#     d_type, d_cardName, d_cardName_type, d_port, d_value = '', '', '', 0, []
#     for device in devices:
#         d_type = device['type']
#         for key, val in sensors_and_executors.items():
#             if int(d_type) in val['devices']:
#                 d_cardName = key
#                 d_cardName_type = val[key]['type']
#                 break
#         d_port = device['port']
#         if mode == 'data':
#             d_value = device['value']
#         if d_cardName_type not in context.keys():
#             context[d_cardName_type] = []
#         context[d_cardName].append({'type': d_type, 'port': d_port, 'values': d_value})
#         # context[d_type] = {'type': d_cardName_type, 'card': d_cardName, 'port': d_port, 'values': d_value}
#     return context



