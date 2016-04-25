# get-peercred

Retrieve `SO_PEERCRED` information from a connected UNIX domain socket.

```javascript
var getCred = require("get-peercred");
getCred(socket._handle.fd); // => { pid: 11115, uid: 1000, gid: 1000 }
```
