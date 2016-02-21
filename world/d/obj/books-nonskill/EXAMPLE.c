// xiyouxiji.c
// created 4-26-97 pickle

/************************************************************/

// inherit and includes. please make sure you have the
// following file included, and others if you wish. these
// files define functions of these books, namely giving
// players gold or mihoutao or dan... and if any more
// functions are planned for these books the file "book.c"
// will be updated, instead of all of them.

#include "book.h";
inherit ITEM;
inherit BOOK;

// please declare this function, and make sure that the
// arguments match the ones you have later in the actual
// function itself.

int do_read(string arg);

/************************************************************/

// create function is just routine.

void create()
{

	// here i changed my convention of being comprehensive
	// about id for several reasons. one being that this will
	// make sure that when the player types in "read <arg>"
	// he will read the book that he intended to read, instead
	// of maybe meaning to read "xiji" but ending up reading
	// the kunlun book.
	// the other reason is that do_read calls another function
	// in book.c in which an exact argument needs to be passed
	// in, and with only one possible id, this avoids any
	// possible ambiguities.

	set_name("〖西游嘻记〗", ({"xiji",}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");

		// i am not sure how the long desc of the book
		// should look like. this is the 3rd format i've
		// tried. if anybody has any better ideas please
		// let me know. the current one does look somewhat
		// awkward still. :(

		set("long", "



※※※※※※※※※
※　　　　　　　※
※"+HIY+
"　 西游嘻记"+NOR+" 　※
※　　　　　　　※
※作者: 不祥　　※
※转录: 明空　　※
※书价: 十两白银※
※※※※※※※※※
\n\n
");
		set("material", "paper");

		// although these books are of entertainment value
		// only, it is possible to benefit from them, so
		// please do not price them lower than 10 silver each.
		// if you want to set it higher, i have no problems
		// that. :PPP
		set("value", 1000);   
	}
}

void init()
{
    add_action("do_read","read");
}

int do_read(string arg)
{
    // this if statement makes sure that the player is entering
    // the right argument. assume that i have a xiji and a kunlun
    // in my hands, then if i type in "read kunlun", then the
    // xiji book will return 0, however, since there is another
    // action "do_read" associated with the book kunlun, i will
    // not see the notify_fail message. so that is a plus.

    if (!this_object()->id(arg))
      return notify_fail("你要读什么？\n");

    // this line calls the function read_book in book.c
    // please please, do not change this line.
    // another thing you need to remember is to add
    // the text file for this book in the directory
    // /d/obj/books-nonskill/text/, and make sure that
    // the file name for the text is the same as for this
    // book, but without any suffix (like .c or .txt) at
    // all...

    read_book(this_player(), this_object()->query("id"));

    // just as a tip, if the book returns 1, the other
    // do_read actions on the player will not be invoked.
    // i had the book do a return 0 before, and it was
    // quite troublesome coz as the book would break into
    // pieces, the player automatically reads another book
    // of the same title in his inventory which troubled
    // me for a long time. :PPP *papaya pickle

    return 1;
}
