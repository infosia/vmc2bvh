# :diamond_shape_with_a_dot_inside: vmc2bvh
**Generate BVH (Biovision Hierarchy) motions from VirtualMotionCapture OSC motion data**

## Dependencies

You need [VirtualMotionCapture](https://sh-akira.github.io/VirtualMotionCapture/) with OSC motion sender enabled. More specifically you'll need [paid version of VirtualMotionCapture](https://akira.fanbox.cc/).

## Usage

- Run `Vmc2Bvh.exe` (on Windows). It listens [VMC protocol](https://sh-akira.github.io/VirtualMotionCaptureProtocol/specification) on port `39539` and then waits for calibration.
- Launch [VirtualMotionCapture](https://sh-akira.github.io/VirtualMotionCapture/). Check `Enable OSC motion sender` from `Settings`.  Note that you'll need [paid version of VirtualMotionCapture](https://akira.fanbox.cc/) that supports OSC motion sender.
- After you calibrate your VRM model in VirtualMotionCapture, `Vmc2Bvh.exe` starts recording motions and generate `<output file name>_HIERARCHY.txt` and  `<output file name>_MOTION.txt` in [BVH format](http://www.dcs.shef.ac.uk/intranet/research/public/resmes/CS0111.pdf).
- In order to stop recording, *type Ctrl-C from your keyboard* on `Vmc2Bvh.exe` console. This will generate resulting BVH file.
- You might want to backup generated BVH file because it will be overwritten on next launch (if you use same output file name, of course).

## Options

- `--port <port number>` ... port number to listen VMC data. `39539` by default.
- `--file <output file name>` ... Output BVH file name to generate. `output.bvh` by default.
- `--bone <root bone name>`  ... Name of root bone. By default it searches `Root` or `Armature`.
- `--in-place`  ... Disable root bone translation. This may be useful to record motions for games.
- `--fps`  ... Frame per second. `60` by default.

## Building

You need [Cmake](https://cmake.org/download/) and Visual Studio with C++ environment installed. You don't need Unity nor UniVRM to build vmc2bvh. There is a CMakeLists.txt file which has been tested with [Cmake](https://cmake.org/download/) on Windows. For instance in order to generate a Visual Studio 10 project, run cmake like this:


```
> mkdir build; cd build
> cmake -G "Visual Studio 10" ..
```

