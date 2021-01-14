


const functions = require('firebase-functions');
const admin = require('firebase-admin');
var firebaseConfig = {
    apiKey: "AIzaSyB6nbp0S3wV59DlaXf_2x1Q4XIpT684Sy0",
    authDomain: "projetol-3efbd.firebaseapp.com",
    databaseURL: "https://projetol-3efbd.firebaseio.com",
    projectId: "projetol-3efbd",
    storageBucket: "projetol-3efbd.appspot.com",
    messagingSenderId: "691623727238",
    appId: "1:691623727238:web:8534c9d02c82ae61360107"
  };

admin.initializeApp(firebaseConfig);

var iot = require('@google-cloud/iot');
var client = new iot.v1.DeviceManagerClient();

exports.helloPubSub = async (event, context) => {
  console.log('event');

  console.log(event);
  console.log('context');

  console.log(context);


   const message = Buffer.from(event.data, 'base64').toString();
  console.log('mensagem enviada ->', message);

  if (typeof JSON.parse(message) === 'object') {
    const { attributes: { deviceId, deviceRegistryId, deviceRegistryLocation, projectId  } } = event
    const db = admin.firestore()

    const { cabinetid, id } = JSON.parse(message)

    const rdb = admin.database().ref(`armario/${cabinetid}/portas/${id}`)

    await db.collection('armario').doc(`${cabinetid}`).collection('portas').doc(`${id}`).set(JSON.parse(message), { merge: true })

    await rdb.set(JSON.parse(message))

    let request = generateRequest(deviceId, deviceRegistryLocation,deviceRegistryId,projectId,  JSON.parse(message), false);

    // Send configuration
    await client.modifyCloudToDeviceConfig(request)

    // Send command
    await client.sendCommandToDevice(request)

    
  } else {
    console.error('mensagem enviada não é um objeto válido:', message);
  }
};

function generateRequest(deviceId, location, registry, project, configData, isBinary) {
    var formattedName = client.devicePath(project, location, registry, deviceId);
    var dataValue;
    if (isBinary) {
        var encoded = cbor.encode(configData);
        dataValue = encoded.toString("base64");
    }
    else {
        dataValue = Buffer.from(JSON.stringify(configData)).toString("base64");
    }
    return {
        name: formattedName,
        binaryData: dataValue
    };
}
