call plug#begin('~/.vim/plugged')

Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
"colorschemes
Plug 'morhetz/gruvbox'

call plug#end()

syntax on
set number
set hlsearch
set incsearch
colorscheme gruvbox
set background=dark

"mappings

map <C-n> :NERDTreeToggle<CR>
