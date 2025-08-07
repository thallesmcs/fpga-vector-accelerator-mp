# 2025-07-16T13:33:07.542131800
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2025")

client.sync_git_example_repo(name="vitis_libraries")

vitis.dispose()

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "test_matriz",hw_design = "C:\Users\Thall\acel_matrizes\design_1_wrapper.xsa",os = "standalone",cpu = "microblaze_0",domain_name = "standalone_microblaze_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

client.delete_component(name="test_matriz")

client.delete_component(name="test_matriz")

vitis.dispose()

comp = client.get_component(name="matrix_mult_hw")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="C_SIMULATION")

comp.run(operation="IMPLEMENTATION")

vitis.dispose()

