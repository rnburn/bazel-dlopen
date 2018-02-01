cc_library(
    name = "b",
    srcs = ["b.cpp"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "a",
    srcs = ["a.cpp"],
    visibility = ["//visibility:public"],
    deps = ["//:b"]
)

cc_test(
    name = "dlopen_test",
    srcs = ["dlopen_test.cpp"],
    visibility = ["//visibility:public"],
    data = ["//:a"],
)

cc_test(
    name = "link_test",
    srcs = ["link_test.cpp"],
    visibility = ["//visibility:public"],
    deps = ["//:a"],
)
