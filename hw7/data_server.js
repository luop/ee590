let jnet = require('./json_net');

let server = new jnet.JSONServer();

server.data = {};

server.on('json_connection',function(jsocket) {

  var address = jsocket.address().address;
  console.log(address);

  var responses = {

    put: function(object) {
      var valid = true;
      var errMsg = "";

      if( !(object.hasOwnProperty('key')) ){
        valid = false;
        errMsg += "key is missing in data. ";
      }else{
        let type = typeof (object.key);
        if ( type != 'string' ){
          valid = false;
          errMsg += "key is not a string. ";
        }
      }

      if( !(object.hasOwnProperty('value')) ){
        valid = false;
        errMsg += "value is missing in data. ";
      }else{
        let type = typeof (object.value);
        if ( type != 'string' && type != 'boolean' && type != 'number' ){
          valid = false;
          errMsg += "value needs to be STRING|NUMBER|BOOLEAN. ";
        }
      }

      if( !(object.hasOwnProperty('timestamp')) ){
        valid = false;
        errMsg += "timestamp is missing in data.";
      }else{
        let type = typeof (object.timestamp);
        if ( type != 'number' || (object.timestamp) < 0 || (object.timestamp) % 1 != 0){
          valid = false;
          errMsg += "timestamp is not a positive integer.";
        }
      }

      if ( valid ){
        server.data[address][object.key] = {value: object.value, timestamp: object.timestamp, received: Math.floor(new Date() / 1000) };
        jsocket.jwrite({ result: "ok"});
      }else{
        jsocket.error(errMsg);
      }
    },

    get: function(object) {
      if( !(object.hasOwnProperty('key')) && !(object.hasOwnProperty('host')) ){
        let count = 0;
        for(var objKey in object) {
          count ++;
        }
        if (count == 1){
          jsocket.jwrite({ result: server.data});
        }else{
          jsocket.error("the command is not well formed");
        }
      }else if( object.hasOwnProperty('key') && !(object.hasOwnProperty('host'))){
        let key_type = typeof (object.key);
        if ( key_type == 'string' ){
          if ( server.data[address].hasOwnProperty(object.key) ){
            jsocket.jwrite({ result: server.data[address][object.key]});
          }else{
            jsocket.error(object.key + " cannot be found");
          }
        }else{
          jsocket.error("the key is not a string");
        }
      }else if( object.hasOwnProperty('key') && object.hasOwnProperty('host') ){
        let key_type = typeof (object.key);
        let host_type = typeof (object.host);
        if ( key_type == 'string' && host_type == 'string' ){
          if ( server.data.hasOwnProperty(object.host) && server.data[object.host].hasOwnProperty(object.key)){
            jsocket.jwrite({ result: server.data[object.host][object.key]});
          }else{
            jsocket.error("data cannot be found");
          }
        }else{
          jsocket.error("the key or the host is not a string");
        }
      }else{
        jsocket.error("the command is not well formed");
      }
    },

    ee590: function(object) {
      console.log(address);
      if( !(server.data.hasOwnProperty(address)) ){
          server.data[address] = {};
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
