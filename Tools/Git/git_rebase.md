# git rebase


## 压缩多个commit

git rebase -i A^...B // 闭区间
git rebase -i A...B // 开区间， 不含A


## 修改某个commit的作者信息
```
git rebase -i A^ // A 表示要修改的那个commit
```
然后出现的交互界面中， 对要修改的commit， 使用edit


退出交互界面后
```
git commit --amend --author="New Author <newauthor@example.com>"
```


最后
```
git rebase --continue
```
