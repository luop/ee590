let jnet = require('./json_net');
//let Stack = require("./stack")

let server = new jnet.JSONServer();

server.data = {};

server.on('json_connection',function(jsocket) {

  var address = jsocket.address().address;
  console.log(address);

  var responses = {

    put: function(object) {
      //server.stack.push({ address: { object.key: {value: object.value, timestamp: object.timestamp, received: Math.floor(new Date() / 1000) }});
      jsocket.jwrite({ result: "ok"});
    },

    get: function(object) {
      //jsocket.jwrite({value: server.stack.pop()});
      jsocket.jwrite({ result: "ok"});
    },

    ee590: function(object) {
      console.log(address);
      if( !(server.data.hasOwnProperty(address)) ){
          server.data[address] = 'ACT';
      }
      jsocket.jwrite({ result: "ok"});
    },

    end: function(object,socket) {
      jsocket.end();
    }

  }

  jsocket.on('json', function(object) {

    if ( responses[object.command] ) {
      if (object.command != 'ee590' && object.command != 'end'){
        if( server.data.hasOwnProperty(address) ){
            responses[object.command](object);
        }else{
          jsocket.error("not yet acquainted");
        }
      }else{
        responses[object.command](object);
      }
    } else {
      jsocket.error("Unknown command '" + object.command + "'");
    }

    console.log(server.data);

  });

  jsocket.on('json_error', function(err) {
    jsocket.jwrite({error: err.message});
  });

});

server.on('error', (err) => {
  throw err;
});

server.listen(8080, () => {
  console.log('server bound');
});
