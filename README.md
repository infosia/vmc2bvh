# :diamond_shape_with_a_dot_inside: vmc2bvh
**Generate BVH motions from VirtualMotionCapture protocol**

## Dependencies

You need [VirtualMotionCapture](https://sh-akira.github.io/VirtualMotionCapture/) with OSC motion sender. More specifically you'll need [paid version of VirtualMotionCapture](https://akira.fanbox.cc/).

## Usage

- Run `Vmc2Bvh.exe` (on Windows). It listens [VMC protocol](https://sh-akira.github.io/VirtualMotionCaptureProtocol/specification) on port `39539` and then waits for calibration.
- Launch [VirtualMotionCapture](https://sh-akira.github.io/VirtualMotionCapture/). Check `Enable OSC motion sender` from `Settings`.  Note that you'll need [paid version of VirtualMotionCapture](https://akira.fanbox.cc/) that supports OSC motion sender.
- After you calibrate your VRM model, `Vmc2Bvh.exe` starts recording motions and generate motion file in [BVH format](http://www.dcs.shef.ac.uk/intranet/research/public/resmes/CS0111.pdf)

## Options

- `--port <port number>` ... port number to listen VMC data. `39539` by default.
- `--file <output file name>` ... Output BVH file name to generate. `output.bvh` by default.
- `--bone <root bone name>`  ... Name of root bone. By default it searches `Root` or `Armature`.


## Building

You don't need Unity nor UniVRM to build vmc2bvh. There is a CMakeLists.txt file which has been tested with cmake on Windows.
For instance in order to generate a Visual Studio 10 project, run cmake like this:


```
> mkdir build; cd build
> cmake -G "Visual Studio 10" ..
``

