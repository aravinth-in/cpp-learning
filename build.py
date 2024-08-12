import os
import subprocess
import sys

def run_command(command):
    result = subprocess.run(command, shell=True)
    if result.returncode != 0:
        print(f"Command failed: {command}")
        sys.exit(result.returncode)

def main():
    # Get the directory where build.py is located
    script_dir = os.path.dirname(os.path.abspath(__file__))
    project_path = script_dir
    build_path = os.path.join(project_path, "build")
    configuration = "Release"  # Change to "Debug" if needed

    # Create build directory if it doesn't exist
    if not os.path.exists(build_path):
        os.makedirs(build_path)

    # Run CMake configuration command
    cmake_configure_command = f'cmake -S "{project_path}" -B "{build_path}" -G "Visual Studio 17 2022" -A x64'
    run_command(cmake_configure_command)

    # Run CMake build command
    cmake_build_command = f'cmake --build "{build_path}" --config {configuration} --verbose'
    run_command(cmake_build_command)

if __name__ == "__main__":
    main()