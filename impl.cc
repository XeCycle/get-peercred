#include <errno.h>
#include <sys/socket.h>

#include <nan.h>

void getCred(const Nan::FunctionCallbackInfo<v8::Value>& info)
{

  if (info.Length() < 1) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Wrong arguments");
    return;
  }

  int fd = info[0]->NumberValue();

  struct ucred cred;
  socklen_t len = sizeof cred;

  if (getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &cred, &len) < 0) {
    Nan::ThrowError(Nan::ErrnoException(errno));
    return;
  }

  auto obj = Nan::New<v8::Object>();
  obj->Set(Nan::New("pid").ToLocalChecked(), Nan::New(cred.pid));
  obj->Set(Nan::New("uid").ToLocalChecked(), Nan::New(cred.uid));
  obj->Set(Nan::New("gid").ToLocalChecked(), Nan::New(cred.gid));

  info.GetReturnValue().Set(obj);

}

void Init(v8::Local<v8::Object> exports)
{
  exports->Set(Nan::New("getCred").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(getCred)->GetFunction());
}

NODE_MODULE(get_cred, Init)
