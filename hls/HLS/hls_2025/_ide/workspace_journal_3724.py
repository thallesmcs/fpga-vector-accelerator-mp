# 2025-07-28T16:24:13.990125700
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2025")

comp = client.get_component(name="soma_array_generic_10000")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp = client.get_component(name="matrix_mult_hw")
comp.run(operation="SYNTHESIS")

comp = client.get_component(name="soma_array_generic_10000")
comp.run(operation="SYNTHESIS")

vitis.dispose()

