Sets up a minimal example to demonstrate using bazel with a `dlopen` test. If you run

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
