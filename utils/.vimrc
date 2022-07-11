call plug#begin('~/.vim/plugged')

Plug 'pbondoer/vim-42header'
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
"colorschemes
Plug 'morhetz/gruvbox'

call plug#end()

syntax on
set ruler
set number
set hlsearch
set incsearch
set tabstop=4
colorscheme gruvbox
set background=dark

"mappings

map <C-n> :NERDTreeToggle<CR>
map <C-t><up> :tabr<cr>
map <C-t><down> :tabl<cr>
map <C-t><left> :tabp<cr>
map <C-t><right> :tabn<cr>

