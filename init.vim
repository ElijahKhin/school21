" Basic settings for Neovim 

set tabstop=4 softtabstop=4
set shiftwidth=4
" set expandtab
set smartindent
set guicursor=
set relativenumber
set nohlsearch
set hidden
set noerrorbells
set noswapfile
set nobackup
set scrolloff=8
set signcolumn=yes
set colorcolumn=80
set background=dark
syntax on

" Set plugins with vim-plug

call plug#begin('~/.vim/plugged')

Plug 'pbondoer/vim-42header'
Plug 'https://github.com/vim-airline/vim-airline'
Plug 'https://github.com/rafi/awesome-vim-colorschemes'

call plug#end()


" Colorscheme's

"colorscheme Iceberg
"colorscheme hybrid
"colorscheme jellybeans
"colorscheme oceanicnext
colorscheme gruvbox

inoremap { {}<Esc>ha
inoremap ( ()<Esc>ha
"inoremap [ []<Esc>ha
