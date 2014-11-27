---
title: 折腾了好久的vim配置
layout: post
category: 技术
tags: vim
---

折腾了很久的vim配置文件，近期我是不打算修改了，测试了下，除了对php支持的不是很好外（主要是对php混乱的缩进），其它语言支持的都很好。传上来当作一个备份吧。

```
"背景色
color molokai
"各种常规设置
set cursorline
set history=1700
"去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限  
set nocompatible  
set nu
set autoread
set so=7
set wildmenu
set wildignore=*.o,*~,*.pyc
set wildignore+=.git\*,.hg\*,.svn\*
set ruler
set cmdheight=2
set hid
set backspace=eol,start,indent
set whichwrap+=<,>,h,l
set ignorecase
set smartcase
set hlsearch
set incsearch 
set lazyredraw 
set magic
set showmatch 
set noerrorbells
set novisualbell
set tm=500
set foldcolumn=1
set guioptions-=m " 隐藏菜单栏 
set guioptions-=T " 隐藏工具栏 
set guioptions-=L " 隐藏左侧滚动条 
set guioptions-=r " 隐藏右侧滚动条 
set guioptions-=b " 隐藏底部滚动条 
set autochdir 
" 设置Python注释字符
autocmd FileType python,shell set commentstring=#\ %s 
autocmd FileType mako set cms=##\ %s
"设置bundle路径
set rtp+=~/.vim/bundle/vundle/
set nocompatible     
syntax enable 
filetype on 
filetype plugin on
filetype indent on
autocmd InsertLeave * se nocul  " 用浅色高亮当前行  
autocmd InsertEnter * se cul    " 用浅色高亮当前行  
set fileencoding=utf-8
set ffs=unix,dos,mac
set formatoptions+=m  
set formatoptions+=B  
set nobackup
set nowb
set noswapfile
set mouse=a
set expandtab
set smarttab
set shiftwidth=4
set tabstop=4
set softtabstop=4
set expandtab
set lbr
set tw=500
set ai 
set si 
set wrap 
set viminfo^=%
" 字体
" set guifont=Liberation\Mono\ 12
set guifont=Courier\ New\ 12  
set laststatus=2
set statusline=\ %{HasPaste()}%F%m%r%h\ %w\ \ CWD:\ %r%{getcwd()}%h\ \ \ Line:\ %l
set list lcs=tab:\|\
"各种键盘映射
inoremap <c-k> <c-x><c-k>
inoremap <c-o> <c-x><c-o>
inoremap <c-l> <c-x><c-l>
inoremap <c-t> <c-x><c-t>
inoremap <c-i> <c-x><c-i>
inoremap <c-]> <c-x><c-]>
inoremap <c-d> <c-x><c-d>
inoremap <c-u> <c-x><c-u>
inoremap <buffer> <C-X><C-U> <C-X><C-U><C-P> 
inoremap <buffer> <C-S-Space> <C-X><C-U><C-P> 
inoremap <C-a> <esc>ggVG
inoremap <C-s> <esc>:w<CR>i
inoremap <C-v> <esc>"+Pi
inoremap <C-c> <esc>"+Yi
inoremap <C-z> <esc>ui
inoremap <C-w> <esc><c-w><c-w>
inoremap ( ()<ESC>i
inoremap { {<CR>}<ESC>o
inoremap [ []<ESC>i
inoremap " ""<ESC>i
inoremap ' ''<ESC>i
inoremap ;; <ESC>o
autocmd filetype java inoremap printf System.out.println()<esc>i
autocmd FileType cpp set dictionary=~/.vim/dict_cpp
map <C-w> <c-w><c-w>
map <C-s> :w<CR>
map <C-a> ggVG
map <C-c> "+Y
map <C-v> "+P
map <C-z> u
map ff <ESC>:NERDTree<CR>
map ss <ESC>:!google-chrome %<CR> 
map fp <ESC>:vsplit<CR>
map cfp <ESC>:split<CR>
"快速添加符号
map tt <ESC>ysiw
map cc <ESC>gcc
map xx <ESC>gcu
map nn gc
map zd <ESC>zfap
map ll :IndentLinesToggle<CR>
map s :!submit.sh<CR><CR>
au FileType python syn keyword pythonDecorator True None False self
au BufNewFile,BufRead *.jinja set syntax=htmljinja
au BufNewFile,BufRead *.mako set ft=mako
au FileType python map <buffer> F :set foldmethod=indent<cr>
au FileType python inoremap <buffer> $r return 
au FileType python inoremap <buffer> $i import 
au FileType python inoremap <buffer> $p print 
au FileType python map <buffer> <leader>1 /class 
au FileType python map <buffer> <leader>2 /def 
au FileType python map <buffer> <leader>C ?class 
au FileType python map <buffer> <leader>D ?def 
au FileType javascript setl fen
au FileType javascript setl nocindent
au FileType javascript imap <c-t> AJS.log();<esc>hi
au FileType javascript imap <c-a> alert();<esc>hi
au FileType javascript inoremap <buffer> $r return 
"回到上次编辑的位置
autocmd BufReadPost *      
            \ if line("'\"") > 0 && line("'\"") <= line("$") |
            \   exe "normal! g`\"" |
            \ endif

if has("gui_running")
    set guioptions-=T
    set guioptions-=e
    set t_Co=256
    set guitablabel=%M\ %t
endif

function! JavaScriptFold() 
    setl foldmethod=syntax
    setl foldlevelstart=1
    syn region foldBraces start=/{/ end=/}/ transparent fold keepend extend
    function! FoldText()
        return substitute(getline(v:foldstart), '{.*', '{...}', '')
    endfunction
    setl foldtext=FoldText()
endfunction

"单文件编译
function Do_OneFileMake()
    exec "w"
    if &filetype=="java"
        exec "!javac %"
        exec "!gnome-terminal -t JAVA -x bash -c \"java %<;rm %<.class;read;\""
    endif
    if &filetype=="python"
        exec "!gnome-terminal -t Python -x bash -c \"python %;read;\""
    endif
    if &filetype=="sh"
        exec "!gnome-terminal -t SH -x bash -c \"sh %; read;\""
    endif
    if &filetype=="c"
        exec "!gnome-terminal -t C -x bash -c \"g++ % -o %<;./%<;rm %<;read;\""
    endif
    if &filetype=="cpp"
        exec "!gnome-terminal -t CPP -x bash -c \"g++ % -o %<;./%<;rm %<;read;\""
    endif
    if &filetype=="markdown"
        exec "!gnome-terminal -t -MD -x bash -c\"submit.sh;read;\""
    endif
    normal o
    exec "c"
endfunction
map e :call Do_OneFileMake()<CR>

function InsertPythonComment()
    exe 'normal'.1.'G'
    let line = getline('.')
    if line =~ '^#!.*$' || line =~ '^#.*coding:.*$'
        return
    endif
    normal O
    call setline('.', '#!/usr/bin/env python')
    normal o
    call setline('.', '# -*- coding:utf-8 -*-')
    normal o
    call cursor(4, 17)
endfunc

function InsertCommentWhenOpen()
    if a:lastline == 1 && !getline('.')
        call InsertPythonComment()
    end
endfunc

"添加cpp头文件
function CppHeadFlie()
    call setline('.','#pragma comment(linker, "/STACK:1024000000,1024000000")') 
    normal o
    call setline('.','#include<set>')
    normal o
    call setline('.','#include<map>')
    normal o
    call setline('.','#include<cmath>')
    normal o
    call setline('.','#include<queue>')
    normal o
    call setline('.','#include<cstdio>')
    normal o
    call setline('.','#include<vector>')
    normal o
    call setline('.','#include<string>')
    normal o
    call setline('.','#include<cstdlib>')
    normal o
    call setline('.','#include<cstring>')
    normal o
    call setline('.','#include<sstream>')
    normal o
    call setline('.','#include<iostream>')
    normal o
    call setline('.','#include<algorithm>')
    normal o
    call setline('.','using namespace std;')
    normal o
    call setline('.','#define eps 1e-6')
    normal o
    call setline('.','#define FI first')
    normal o
    call setline('.','#define SE second')
    normal o
    call setline('.','#define DL double')
    normal o
    call setline('.','#define PB push_back')
    normal o
    call setline('.','#define MP make_pair')
    normal o
    call setline('.','#define LL long long')
    normal o
    call setline('.','#define INF 0x7fffffff')
    normal o
    call setline('.','#define VI vector<int>')
    normal o
    call setline('.','#define VII vector<VI >')
    normal o
    call setline('.','#define VS vector<string>')
    normal o
    call setline('.','#define MII map<int,int>')
    normal o
    call setline('.','#define MIS map<int,string>')
    normal o
    call setline('.','#define MSI map<string,int>')
    normal o
    call setline('.','const double PI = acos(-1.0);')
    normal o
    call setline('.','#define ALL(C) C.bein(),C.end()')
    normal o
    call setline('.','#define FILLC(c,v) fill(ALL(c),v);')
    normal o
    call setline('.','#define CLR(a,b) memeset(a,b,sizeof(a));')
    normal o
    call setline('.','#define input freopen("in.cpp","r",stdin);')
    normal o
    call setline('.','#define FORN(i,to) for(int i = 0;i < to;i ++)')
    normal o
    call setline('.','#define FILLA(a,b) fill(a,a+sizeof(a)/sizeof(a[0]),b);')
    normal o
    call setline('.','#define FORI(i,from,to) for(int i = from;i < to;i ++)')
    normal o
    call setline('.','#define FORD(i,from,to) for(int i = from;i > to;i --)')
    normal o
    call setline('.','#define CFI(it,v) for(typeof(v.begin()) it = v.begin();it != v.end();it ++)')
    normal o
    call setline('.','int main(){')
    normal o
    normal o
    normal o
    normal o
    normal o
    normal o
    normal o
    call setline('.',"    return 0;")
    normal o
    call setline('.','}')
    normal o
    call cursor(40,4)
endfunc

function CallCppFunction()
     if a:lastline == 1 && !getline('.')
        call CppHeadFlie()
    end
endfunc

"添加java头文件
function JavaFile()
    call setline('.','import java.io.*;')
    normal o
    call setline('.','import java.awt.*;')
    normal o
    call setline('.','import java.util.*;')
    normal o
    call setline('.','import java.math.*;')
    normal o
    call setline('.','import javax.swing.*;')
    normal o
    call setline('.','import java.applet.*;')
    call setline('.','public class '.expand("%<").expand('{'))
    normal o
    call setline('.','    public static void main(String[] args){')
    normal o
    normal o
    call setline('.','    }')
    normal o
    call setline('.','}')
    call cursor(8,9)
endfunc

function CallJavaFunction()
    if a:lastline == 1 && !getline('.')
        call JavaFile()
    end
endfunc

"根据文件类型加载相应函数
au FileType javascript call JavaScriptFold()
au FileType cpp :%call CallCppFunction()
au FileType java :%call CallJavaFunction()
au FileType python :%call InsertCommentWhenOpen()


"各种插件
call vundle#rc()
Bundle "airblade/vim-gitgutter"
Bundle "gregsexton/gitv"
Bundle "tpope/vim-commentary"
Bundle "tpope/vim-surround"
Bundle "Raimondi/delimitMate"
Bundle "mattn/emmet-vim"
Bundle 'scrooloose/nerdtree'
Bundle "MarcWeber/vim-addon-mw-utils"
Bundle "tomtom/tlib_vim"
Bundle "garbas/vim-snipmate"
Bundle "honza/vim-snippets"
Bundle 'pkufranky/VimRepress'
Bundle 'hallison/vim-markdown'
Bundle "MarcWeber/vim-addon-mw-utils"
Bundle "tomtom/tlib_vim"
Bundle "garbas/vim-snipmate"
Bundle "honza/vim-snippets"
Bundle 'gmarik/vundle'
Bundle 'kien/ctrlp.vim'
Bundle 'sukima/xmledit'
Bundle 'sjl/gundo.vim'
Bundle 'jiangmiao/auto-pairs'
Bundle 'SirVer/ultisnips'
Bundle 'scrooloose/syntastic'
Bundle 't9md/vim-quickhl'
Bundle 'Lokaltog/vim-powerline'
Bundle 'scrooloose/nerdcommenter'
Bundle 'hdima/python-syntax' 
Bundle 'Yggdroot/indentLine'
Bundle 'Shougo/neocomplete'
Bundle 'kevinw/pyflakes-vim'  
Bundle 'pangloss/vim-javascript' 
Bundle 'mathematic.vim'
Bundle 'vim-scripts/Pydiction'
"插件设置
let mapleader = ","
let g:mapleader = ","
let g:Source="/home/wangzhili/wzl/"  
let python_highlight_all = 1
let g:author = 'wangzhili'
let g:Email  = 'wangstdio.h@gmail.com'
let g:html_indent_inctags = "html,body,head,tbody"  
let g:html_indent_script1 = "inc"  
let g:html_indent_style1 = "inc"
let g:pyflakes_use_quickfix = 0 
let g:indentLine_color_gui = '#BEBEBE'
let g:indentLine_char = '┆'
let g:acp_enableAtStartup = 0
let g:neocomplete#enable_at_startup = 1
let g:neocomplete#enable_smart_case = 1
let g:neocomplete#sources#syntax#min_keyword_length = 3
let g:SuperTabRetainCompletionType = 2
let g:SuperTabDefaultCompletionType = "<C-X><C-O>" 
let g:pydiction_location = '~/.vim/bundle/Pydiction/complete-dict'
let g:pydiction_menu_height = 10
autocmd Filetype java setlocal omnifunc=javacomplete#Complete 
autocmd Filetype java setlocal completefunc=javacomplete#CompleteParamsInfo 
autocmd Filetype java,javascript,jsp inoremap <buffer>  .  .<C-X><C-O><C-P>
autocmd FileType python setlocal completeopt-=preview
autocmd FileType css setlocal omnifunc=csscomplete#CompleteCSS
autocmd FileType html,markdown setlocal omnifunc=htmlcomplete#CompleteTags
autocmd FileType javascript setlocal omnifunc=javascriptcomplete#CompleteJS
autocmd FileType python setlocal omnifunc=pythoncomplete#Complete
autocmd FileType xml setlocal omnifunc=xmlcomplete#CompleteTags




" 整行补全                        CTRL-X CTRL-L
" 根据语言进行补全                CTRL-X CTRL-O
" 根据当前文件里关键字补全        CTRL-X CTRL-N
" 根据字典补全                    CTRL-X CTRL-K
" 根据同义词字典补全              CTRL-X CTRL-T
" 根据头文件内关键字补全          CTRL-X CTRL-I
" 根据标签补全                    CTRL-X CTRL-]
" 补全文件名                      CTRL-X CTRL-F
" 补全宏定义                      CTRL-X CTRL-D
" 补全vim命令                     CTRL-X CTRL-V
" 用户自定义补全方式              CTRL-X CTRL-U
" 拼写建议                        CTRL-X CTRL-S 
" 全文补全(向前)                  CTRL-P
" 全文补全(向后)                  CTRL-N
```
