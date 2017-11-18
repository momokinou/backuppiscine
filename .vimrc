" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    .vimrc                                             :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2017/11/18 12:25:14 by qmoricea          #+#    #+#              "
"    Updated: 2017/11/18 16:59:37 by qmoricea         ###   ########.fr        "
"                                                                              "
" **************************************************************************** "

set nocompatible " Desactive la compatibilite VI
set number       " Numéros de ligne
set smartindent  " Indentation intelligente
set autoindent   " Conserve indentation sur nouvelle ligne
set ruler        " Affiche le curseur
set mouse=a      " Prise en charge souris
syntax on        " Coloration synthaxique
set tabstop=4    " Identation toutes les 4 colonnes
set shiftwidth=4 " Bis
set showcmd      " Affiche les commandes incompletes
set showmatch    " Mettre en evidence 2 parantheses qui correspondent
set textwidth=80 " Nombre de caracteres maximums par lignes

highlight CursorLine term=bold cterm=bold guibg=Grey40
highlight Error gui=bold guifg=red guibg=yellow

set hlsearch     " Active surbrillance
set incsearch    " Se deplace pendant la frappe
set ignorecase   " Ignore la casse
set cursorline   " Highlight la ligne ou aue l'on edit
set backspace=indent,eol,start " Retour en arriere intelligent
set shiftround   " identation a la marque de tab la plus proche
set statusline+=%#CursorColumn#

let sbv_tab_placeholder='»·'  " Highlight du tab
let sbv_space_placeholder='·' " Highlight de l'espace

" Highlight des espace Error
highlight ExtraWhitespace ctermbg=red
match ExtraWhitespace /  /
match ExtraWhitespace /\s\+$\

" Highlight de l'overlenght
highlight OverLength ctermbg=blue
match OverLength /\%80v.\+/

" Autoclose des brackets, etc ...
ino " ""<left>
ino ' ''<left>
ino ( ()<left>
ino [ []<left>
ino { {}<left>
ino {<CR> {<CR>}<ESC>O
ino {;<CR> {<CR>};<ESC>O
