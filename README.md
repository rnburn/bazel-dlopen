Sets up a minimal example to demonstrate setting up bazel to run a test with `dlopen`. If you run

```
bazel test //...
```

the `dlopen_test` should fail with the message

```
dlopen(./_solib_darwin_x86_64/libliba.so, 6): Symbol not found: __Z1gv
  Referenced from: ./_solib_darwin_x86_64/libliba.so
  Expected in: flat namespace
 in ./_solib_darwin_x86_64/libliba.so
```
