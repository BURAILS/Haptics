import asyncio
import bleak

BLUE_ENABLE_UUID = "a9ae2041-7f44-4422-aff0-0761d8bc8c0a"
BLUE_PAN_UUID = "1a749437-6c6b-42b0-87c1-5badc0166f0d"
BLUE_TILT_UUID = "cd695109-af7d-4d8f-939e-07ca9adee1ad"
BLUE_UPRIGHT_UUID = "f03ef807-3959-4c3f-998d-d06a43cacb7d"
BLUE_ARM_UUID = "91b79e3e-5905-4e89-a8c1-a6851e5c9ff5"

async def run():
    devices = await bleak.discover()

    for d in devices:
        if d.name == "CameraBoom":
            return d


async def printServices(address, loop):
    async with bleak.BleakClient(address, loop=loop) as client:
        svcs = await client.get_services();
        print("Services: ", svcs)


async def printChar(address, loop):
    async with bleak.BleakClient(address, loop=loop) as client:
        blueEnable = await client.read_gatt_char(BLUE_ENABLE_UUID)
        bluePan = await client.read_gatt_char(BLUE_PAN_UUID)
        blueTilt = await client.read_gatt_char(BLUE_TILT_UUID)
        blueUpright = await client.read_gatt_char(BLUE_UPRIGHT_UUID)
        blueArm = await client.read_gatt_char(BLUE_ARM_UUID)
        print("Blue Enable: ", blueEnable)
        print("Blue Pan: ", bluePan)
        print("Blue Tilt: ", blueTilt)
        print("Blue Upright: ", blueUpright)
        print("Blue Arm: ", blueArm)

async def writeChar(address, loop):
    async with bleak.BleakClient(address, loop=loop) as client:
        blueEnableW = bytearray([0x01])
        await client.write_gatt_char(BLUE_ENABLE_UUID, blueEnableW)

loop = asyncio.get_event_loop()
camera_boom = loop.run_until_complete(run())
loop.run_until_complete(writeChar(camera_boom.address, loop))
