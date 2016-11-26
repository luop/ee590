let jnet  = require('./json_net');

let client = jnet.JSONSocket();

function test_connection() {

  var cpus = require('os').cpus();
  var len = cpus.length;
  var total, cpu;
  var p_total = 0;
  for(var i = 0; i < len; i++) {
    cpu = cpus[i];
    total = 0;

    for(var type in cpu.times) {
      total += cpu.times[type];
    }

    p_total += cpu.times.user / total;
  }

  setTimeout(function() {
    client.jwrite({ command: "ee590"});
    setTimeout(function() {
      client.jwrite({ command: "put", key: "cpu load", value: Math.round(100 * p_total/len), timestamp: Math.floor(new Date() / 1000)});
      setTimeout(function() {
        client.jwrite({ command: "get"});
        setTimeout(function() {
          client.jwrite({ command: "get", key: "cpu load"});
          setTimeout(function() {
            client.jwrite({ command: "get", key: "cpu load", host: '::ffff:127.0.0.1' });
            setTimeout(function() {
              client.jwrite({ command: "end"});
            }, 1000);
          }, 1000)
        }, 1000);
      }, 1000);
    }, 1000);
  }, 1000);
  //client.jwrite({ command: "ee590"});
  //client.jwrite({ command: "put", key: "cpu load", value: Math.round(100 * p_total/len), timestamp: Math.floor(new Date() / 1000)});
  //client.jwrite({ command: "get"});
  //client.jwrite({ command: "get", key: "cpu load"});
  //client.jwrite({ command: "get", key: "cpu load", host: process.argv[2] });
  //client.jwrite({ command: "end"});
}

client.on('connect', function() {
  test_connection();
});

client.on('error', (err) => {
  throw err;
});

if ( process.argv.length == 4 ){
  let hostname = process.argv[2];
  let port = process.argv[3];
  client.connect(port, hostname);
}else{
  console.log("Usage: node save_cpu.js hostname port")
}
