var getCred = require("./");

var $net = require("net");
var AEQ = require("assert").strictEqual;

var server = $net.createServer(function(socket) {
  var cred = getCred(socket._handle.fd);
  console.log(cred);
  AEQ(cred.pid, process.pid);
  AEQ(cred.uid, process.getuid());
  AEQ(cred.gid, process.getgid());
  socket.end();
});

var socketPath = "./test-socket";

require("fs").unlink(socketPath, function() {
  server.listen(socketPath, function() {
    var client = $net.connect(socketPath, function() {
      client.on("end", function() { server.close(); });
    });
  });
});
