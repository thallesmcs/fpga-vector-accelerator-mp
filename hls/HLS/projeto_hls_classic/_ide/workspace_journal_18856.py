# 2025-06-23T16:15:29.205659700
import vitis

client = vitis.create_client()
client.set_workspace(path="projeto_hls")

comp = client.get_component(name="adder")
comp.run(operation="C_SIMULATION")

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

status = client.add_platform_repos(platform=["c:\Users\Thall\adder"])

status = client.add_platform_repos(platform=["f:\Xilinx\projeto_hls\adder\adder"])

proj = client.create_sys_project(name="Adder_System", platform="C:\Users\Thall\adder\teste_adder_wrapper.xsa", template="empty_accelerated_application")

proj = client.create_sys_project(name="system_project", platform="C:\Users\Thall\adder\adder_fixed.xsa", template="empty_accelerated_application")

proj = client.create_sys_project(name="system_project", platform="C:\Users\Thall\adder\adder_fixed.xsa", template="empty_accelerated_application")

vitis.dispose()

