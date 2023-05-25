# 230505
## vscode

```
	// -------------- cmake
	"cmake.configureEnvironment": {
		"CMAKE_EXPORT_COMPILE_COMMANDS": "ON",
	},
	"cmake.buildEnvironment": {
		"LD_LIBRARY_PATH": "/integration/lib"
	},
	"cmake.configureArgs": [
		"-DDEBUG_VISUALIZER=ON",
		"-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
		"-DCMAKE_TOOLCHAIN_FILE=/root/toolchain.cmake",
		"-DCMAKE_INSTALL_PREFIX=/root/pnc_out/x86"
		// cmake .. -DDEBUG_VISUALIZER=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON  -DCMAKE_TOOLCHAIN_FILE=/root/toolchain.cmake -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_INSTALL_PREFIX=/root/pnc_out/x86
	],
	"cmake.sourceDirectory": "${workspaceFolder}",
	"cmake.buildDirectory": "${workspaceFolder}/build-clangd",
	// "cmake.sourceDirectory": "/root/world_model",
	// "cmake.buildDirectory": "/root/world_model/build-clangd",
	"cmake.configureOnOpen": false,
	"cmake.autoSelectActiveFolder": true,
	"cmake.generator": "Unix Makefiles",
	"cmake.preferredGenerators": [
		"Kate - Unix Makefiles",
		"Ninja",
	],
	// 
	// 
	//
	// c/c++
	// 关闭 C/C++ 插件冲突的功能 https://zsien.cn/vscode-uses-clangd-to-provide-intellisense-and-autocomplete/
	// 因为还需要 Debug，所以不能完全禁用掉 C/C++ 插件。不过，像智能提示、自动补全、错误提示就都可以禁掉啦。
	"C_Cpp.errorSquiggles": "Disabled",
	"C_Cpp.intelliSenseEngineFallback": "Disabled",
	"C_Cpp.intelliSenseEngine": "Disabled",
	"C_Cpp.autocomplete": "Disabled", // So you don't get autocomplete from both extensions.
	//
	//
	//
	//
	///--------------- clangd
	// "clangd.path": "/root/.vscode-server/data/User/globalStorage/llvm-vs-code-extensions.vscode-clangd/install/16.0.2/clangd_16.0.2/bin/clangd",
	"clangd.path": "/root/.vscode-server/data/User/globalStorage/llvm-vs-code-extensions.vscode-clangd/install/15.0.6/clangd_15.0.6/bin/clangd",
	"clangd.arguments": [
		// 让 Clangd 生成更详细的日志
		"--log=verbose",
		// 输出的 JSON 文件更美观
		"--pretty",
		// 跨文件重命名变量
		"--cross-file-rename",
		// 在参数前加入-，如-modernize-use-trailing-return-type，将会禁用某一规则
		"--clang-tidy",
		// "--clang-tidy-checks=cppcoreguidelines-*,performance-*,bugprone-*,portability-*,modernize-*,google-*",
		//
		"--compile-commands-dir=/root/world_model/build-clangd/",
		// "--compile-commands-dir=${workspaceFolder}/build-clangd/",
		// "--compile-commands-dir=/root/world_model/build/",
		// "--compile-commands-dir=${workspaceFolder}/build/",
		//
		"--background-index",
		"--limit-references=0",
		// "--completion-parse=auto",
		// "--skipParsing=false",
		// When disabled, completions contain only parentheses for function calls.
		// When enabled, completions also contain placeholders for method parametersPcmake
		"--function-arg-placeholders=true", // 用tab切换
		"--header-insertion-decorators", // 用圆点区分头文件是否已经插入
		"-j=8",
		// "--query-driver=/usr/bin/clang++",
		"--query-driver=/usr/bin/g++,/usr/bin/c++,/usr/bin/clang++,/usr/bin/clang",
		"--fallback-style=Google",
		// "--header-insertion=iwyu",
		"--header-insertion=never",
		// pch优化的位置(memory 或 disk，选择memory会增加内存开销，但会提升性能) 推荐在板子上使用disk
		"--pch-storage=memory",
		"--ranking-model=heuristics",
		"--enable-config",
		"--all-scopes-completion", // 全代码库补全
		"--completion-style=bundled", // 详细补全
	],
	"clangd.onConfigChanged": "restart",
	"clangd.restartAfterCrash": true,
	"clangd.checkUpdates": false,
	"clangd.trace": "verbose",
	"clang.completion.completeMacros": false,
	"clang.completion.enable": false,
	"clang-format.fallbackStyle": "google",
	"clang-format.language.cpp.style": "file",
	"clang-format.assumeFilename": "${workspaceFolder}/.clang-format",
	"clang-format.executable": "clang-format",
	"clang-format.executable.linux": "/usr/bin/clang-format",
```

## .config文件夹下的设置
```
Diagnostics:
  ClangTidy:
    Add:
      [
        performance-*,
        bugprone-*,
        portability-*,
        modernize-*,
        google-*,
        misc-*,
        cppcoreguidelines-*
        -std=c++17
        -Wno-documentation
      ]
    Remove:
      [
        modernize-use-trailing-return-type,
        modernize-use-nodiscard
      ]
    CheckOptions:
      WarnOnFloatingPointNarrowingConversion: false
Index:
  Background: Build

CompileFlags:
  Add: [
        -include=/root/pnc_out/x86/include/worldmodel/traffic_light_processor/traffic_light_processor.h,
        -I/root/pnc_out/x86/include
        ]
```