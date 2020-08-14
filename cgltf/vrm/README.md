# :diamond_shape_with_a_dot_inside: VRM type generator
**VRM types/parser functions generator**

## Usage: Generate VRM types

You'll need to install Node.js.

```
> node vrm_type_generator.js
```

This generates `vrm_types.h`, `vrm_types.inl` and `vrm_write.inl`.

## Testing VRM files

There is a `test_write` program and Node.js script that checkes vrm file format in in various way. Here's one way to build the test:

```
cd test ; mkdir build ; cd build ; cmake .. -DCMAKE_BUILD_TYPE=Debug
```

This generates Visual Studio project on Windows and you need to launch IDE to build it manually when you use Windows. You can run `make -j` on other platforms. After building `test_write` then you can test VRM files;

```
> test_write your.vrm
```

This tests basic VRM values and generates two files; your`.vrm.in.json` files is the JSON content that is extracted from VRM. your`.vrm.out.json` is the JSON content that is exported from cgltf data. Under `test` directory there are scripts to compare values in order to validate VRM;

```
> node vrm_format_check.js your.vrm.in.json your.vrm.out.json
```

You might want to run all tests for your VRM files all at once, then;

```
> node run_test_write.js
```

This will run all test above for all VRM files against `test/models/*.vrm`.