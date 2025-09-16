@echo off
setlocal EnableDelayedExpansion

echo =========================================
echo Running test_4 with different parameters
echo =========================================

rem Находим exe файл
set "EXE_PATH="
if exist "build\bin\Debug\test_4.exe" (
    set "EXE_PATH=build\bin\Debug\test_4.exe"
) else if exist "build\bin\Release\test_4.exe" (
    set "EXE_PATH=build\bin\Release\test_4.exe"
) else if exist "build\bin\test_4.exe" (
    set "EXE_PATH=build\bin\test_4.exe"
) else (
    echo ERROR: Cannot find test_4.exe!
    exit /b 1
)

echo Found exe at: %EXE_PATH%
echo.

rem Тест 1
echo [Test 1] N=1000000, Start=1.0, Target=500.0
"%EXE_PATH%" 1000000 1.0 500.0 > test_4_output_1.txt 2>&1
echo   - Saved to test_4_output_1.txt

rem Тест 2
echo [Test 2] N=5000000, Start=0.5, Target=2500000.0
"%EXE_PATH%" 5000000 0.5 2500000.0 > test_4_output_2.txt 2>&1
echo   - Saved to test_4_output_2.txt

rem Тест 3
echo [Test 3] N=10000000, Start=1.0, Target=5000000.0
"%EXE_PATH%" 10000000 1.0 5000000.0 > test_4_output_3.txt 2>&1
echo   - Saved to test_4_output_3.txt

rem Тест 4
echo [Test 4] N=2000000, Start=2.0, Target=1000000.0
"%EXE_PATH%" 2000000 2.0 1000000.0 > test_4_output_4.txt 2>&1
echo   - Saved to test_4_output_4.txt

rem Тест 5
echo [Test 5] N=8000000, Start=0.1, Target=4000000.0
"%EXE_PATH%" 8000000 0.1 4000000.0 > test_4_output_5.txt 2>&1
echo   - Saved to test_4_output_5.txt

rem Тест 6
echo [Test 6] N=3000000, Start=5.0, Target=1500000.0
"%EXE_PATH%" 3000000 5.0 1500000.0 > test_4_output_6.txt 2>&1
echo   - Saved to test_4_output_6.txt

rem Тест 7
echo [Test 7] N=7000000, Start=0.8, Target=3500000.0
"%EXE_PATH%" 7000000 0.8 3500000.0 > test_4_output_7.txt 2>&1
echo   - Saved to test_4_output_7.txt

rem Тест 8
echo [Test 8] N=4000000, Start=3.0, Target=2000000.0
"%EXE_PATH%" 4000000 3.0 2000000.0 > test_4_output_8.txt 2>&1
echo   - Saved to test_4_output_8.txt

rem Тест 9
echo [Test 9] N=9000000, Start=0.2, Target=4500000.0
"%EXE_PATH%" 9000000 0.2 4500000.0 > test_4_output_9.txt 2>&1
echo   - Saved to test_4_output_9.txt

rem Тест 10
echo [Test 10] N=6000000, Start=4.0, Target=3000000.0
"%EXE_PATH%" 6000000 4.0 3000000.0 > test_4_output_10.txt 2>&1
echo   - Saved to test_4_output_10.txt

echo.
echo =========================================
echo All tests completed successfully!
echo Check test_4_output_*.txt files
echo =========================================