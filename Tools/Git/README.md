# Git

- 快速删除远端分支
  ``` shell
  git push :branch_name
  ```

- 同时pick多个commit
``` shell
git cherry-pick SHA1_1 SHA1_2 SHA1_3

git cherry-pick A..B   左半开区间 （A，B]

git cherry-pick A^..B  闭合区间 [A, B]
```