# 230505
## vscode

```
	{
	// -------------- cmake
	"cmake.configureEnvironment": {
		"CMAKE_EXPORT_COMPILE_COMMANDS": "ON",
	},
	"cmake.buildEnvironment": {
		"LD_LIBRARY_PATH": "/integration/lib"
	},
	"cmake.configureArgs": [
		"-DDEBUG_VISUALIZER=ON",
		"-DBUILD_TESTS=ON",
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
	"cmake.autoSelectActiveFolder": false,
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
	"clangd.path": "/root/.vscode-server/data/User/globalStorage/llvm-vs-code-extensions.vscode-clangd/install/16.0.2/clangd_16.0.2/bin/clangd",
	// "clangd.path": "/root/.vscode-server/data/User/globalStorage/llvm-vs-code-extensions.vscode-clangd/install/15.0.6/clangd_15.0.6/bin/clangd",
	"clangd.arguments": [
		// 让 Clangd 生成更详细的日志
		"--log=verbose",
		// 输出的 JSON 文件更美观
		"--pretty",
		// 跨文件重命名变量
		"--rename-file-limit=0",
		// 在参数前加入-，如-modernize-use-trailing-return-type，将会禁用某一规则
		"--clang-tidy",
		// "--clang-tidy-checks=cppcoreguidelines-*,performance-*,bugprone-*,portability-*,modernize-*,google-*",
		//
		// "--compile-commands-dir=/root/world_model/build-clangd/",
		// "--compile-commands-dir=/root/world_model/build/",
		"--compile-commands-dir=${workspaceFolder}/build-clangd/",
		// "--compile-commands-dir=/root/world_model/build/",
		// "--compile-commands-dir=${workspaceFolder}/build/",
		//
		"--background-index",
		"--background-index-priority=normal",
		"--limit-results=0",
		"--limit-references=0",
		// When disabled, completions contain only parentheses for function calls.
		// When enabled, completions also contain placeholders for method parametersPcmake
		"--function-arg-placeholders=true", // 用tab切换
		"--header-insertion-decorators", // 用圆点区分头文件是否已经插入
		"-j=12",
		"--query-driver=/usr/bin/clang,/usr/bin/g++,/usr/bin/c++,/usr/bin/clang",
		"--fallback-style=Google",
		"--header-insertion=never",
		// pch优化的位置(memory 或 disk，选择memory会增加内存开销，但会提升性能) 推荐在板子上使用disk
		"--pch-storage=memory",
		"--malloc-trim",
		// "--ranking-model=heuristics",
		"--enable-config",
		"--all-scopes-completion", // 全代码库补全
		"--completion-style=bundled", // 详细补全
	],
	"clangd.onConfigChanged": "restart",
	"clangd.restartAfterCrash": true,
	"clangd.checkUpdates": false,
	// "clangd.trace": "verbose",
	"clang.completion.completeMacros": false,
	"clang.completion.enable": false,
	"clang-format.fallbackStyle": "google",
	"clang-format.language.cpp.style": "file",
	"clang-format.assumeFilename": "${workspaceFolder}/.clang-format",
	"clang-format.executable": "clang-format",
	"clang-format.executable.linux": "/usr/bin/clang-format",
	//
	//
	//-------------- editor
	"editor.formatOnPaste": true,
	"editor.formatOnType": true,
	"editor.formatOnSaveMode": "modificationsIfAvailable",
	"editor.inlayHints.enabled": "offUnlessPressed",
	"editor.fontFamily": "'Nerd Font Complete Mono', 'Nerd Font Mono', 'Noto Sans Mono', 'Droid Sans Mono', 'monospace', monospace",
	"editor.defaultFormatter": "mjohns.clang-format",
	// "editor.parameterHints.enabled": false,
	//
	//
	// ------------------ python
	"python.analysis.completeFunctionParens": true,
	"python.analysis.inlayHints.functionReturnTypes": true,
	// 
	// 
	// -----------------guides 插件
	"guides.normal.color.dark": "rgba(91, 91, 91, 0.6)",
	"guides.normal.color.light": "rgba(220, 220, 220, 0.7)",
	"guides.active.color.dark": "rgba(210, 110, 210, 0.6)",
	"guides.active.color.light": "rgba(200, 100, 100, 0.7)",
	"guides.active.style": "dashed",
	"guides.normal.style": "dashed",
	"guides.stack.style": "dashed",
	// 作者：王仕军
	// 链接：https: //juejin.cn/post/6844903591019282446
	// 来源：稀土掘金
	// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	//
	//
	// ------------------光标高亮
	"workbench.colorCustomizations": {
		"editor.lineHighlightBackground": "#49b2b93d", //修改光标所在行的背景色
		"editor.lineHighlightBorder": "#ffffff30" //修改光标所在行的边框色
	},
	// 
	// ------------------ lldb
	// 
	"lldb.consoleMode": "evaluate", //调试控制台模式为终端命令模式，可调用lldb命令
	"lldb.launch.sourceLanguages": [ //调试语言
		"cpp",
		"c"
	],
	"lldb.launch.expressions": "native", //使用原生表达式
	"lldb.displayFormat": "auto",
	"lldb.dereferencePointers": false,
	"lldb.showDisassembly": "never",
	//
	// ------------------ git graph
	"git-graph.commitDetailsView.location": "Docked to Bottom",
	"git-graph.maxDepthOfRepoSearch": 0,
	//
	// -------------------
	"files.autoSave": "afterDelay",
	"terminal.integrated.fontFamily": "'Nerd Font Complete Mono', 'Nerd Font Mono','Noto Sans Mono', 'Droid Sans Mono', 'monospace', monospace",
	"terminal.integrated.allowChords": false,
	"workbench.tree.renderIndentGuides": "always",
	"[cpp]": {
		"editor.defaultFormatter": "mjohns.clang-format"
	},
	"[yaml]": {
		"editor.defaultFormatter": "redhat.vscode-yaml"
	},
	"editor.inlayHints.padding": true,
	// "[cmake]": {
	// 	"editor.defaultFormatter": "josetr.cmake-language-support-vscode"
	// },
}
```

## .config文件夹下的设置
```
#  ref: https://clangd.llvm.org/config#files
Diagnostics:
  UnusedIncludes: Strict
  ClangTidy:
    Add:
      [
        performance-*,
        bugprone-*,
        portability-*,
        modernize*,
        google-*,
        misc-*,
        cppcoreguidelines-*,
      ]
    Remove: [modernize-use-trailing-return-type]
    CheckOptions:
      WarnOnFloatingPointNarrowingConversion: false
Index:
  StandardLibrary: Yes
  Background: Build
  # Background: Skip # Disable slow background indexing of these files

InlayHints:
  Designators: Yes
  Enabled: Yes
  ParameterNames: Yes
  DeducedTypes: Yes

Hover:
  ShowAKA: Yes

CompileFlags: # Tweak the parse settings
  Add: [
      -xc++,
      -Wall,
      -std=c++17,
      -DDEBUG_VISUALIZER=ON,
      -DBUILD_TESTS=OFF,
      -DCMAKE_EXPORT_COMPILE_COMMANDS=ON,
      -DCMAKE_TOOLCHAIN_FILE=/root/toolchain.cmake,
      -DCMAKE_INSTALL_PREFIX=/root/pnc_out/x86,
    ] # treat all files as C++, enable more warnings
  Remove: -W* # strip all other warning-related flags
  Compiler: g++ # Change argv[0] of compile flags to `clang++`
  # CompilationDatabase: [/root/world_model/build-clangd]

```