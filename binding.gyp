{
  "targets": [
    {
      "target_name": "get-cred",
      "sources": [ "impl.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
