{
  "targets": [
    {
      "target_name": "get-cred",
      "sources": [ "impl.cc" ],
      "cflags": ["-std=c++11"],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
