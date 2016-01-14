#! /bin/bash

function main(){
    files='--all'
    comment='blog'
    if [ $# -ne 0 ];then
        files=$1
        if [ $# -gt 1 ];then
            comment=$2
        fi
    fi
    git status
    if [ ${files}x="--all"x ];then
        git diff
    else
        git diff $files
    fi
    git add ${files}
    git commit -m "\"${files}\""
    git push origin master
}

main $*
