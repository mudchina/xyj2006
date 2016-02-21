// workroom.c
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIB"À¬»ø³¡"NOR);
	set("long", @LONG
¶¼ÊÇÀ¬»ø
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
 "down":"/d/wiz/wizroom",
	]));

	set("sleep_room", "1");
        set("valid_startroom","1");
	set("item_desc", ([
		"sea" : "²¨ÌÎÐÚÓ¿£¬¾ªÌÔÅÄ°¶,ºÃÒ»·ù×³Àö¾°¹Û£¡\n",
	]));
	setup();
// call_other("/u/cheer/obj/board", "???");
}

void init()
{
	add_action("look_paper","look");
}

int look_paper(string arg)
{
	if( !arg || arg!="paper" ) return 0;

	write(HIY"                               µ÷É«°åËµÃ÷\n"NOR);
	write("Black esc[30m BLK       "+BLK"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Red esc[31m RED       "+RED"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Green esc[32m GRN       "+GRN"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Yellow esc[33m YEL    "+YEL"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Blue esc[34m BLU        "+BLU"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Magenta esc[35m MAG   "+MAG"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Cyan esc[36m  CYN       "+CYN"¡ö¡ö¡ö¡ö¡ö"NOR+" ; White esc[37m WHT     "+WHT"¡ö¡ö¡ö¡ö¡ö\n\n"NOR);

	write("Red esc[1;31m HIR       "+HIR"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Green esc[1;32m HIG   "+HIG"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Yellow esc[1;33m HIY    "+HIY"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Blue esc[1;34m HIB    "+HIB"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Magenta esc[1;35m HIM   "+HIM"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Cyan esc[1;36m HIC    "+HIC"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("White esc[1;37m HIW     "+HIW"¡ö¡ö¡ö¡ö¡ö\n\n"NOR);

	write("Red esc[42;1m HBRED     "+HBRED"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Green esc[42;1m HBGRN "+HBGRN"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Yellow esc[43;1m HBYEL  "+HBYEL"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Blue esc[44;1m HBBLU  "+HBBLU"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Magenta esc[45;1m HBMAG "+HBMAG"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Cyan esc[46;1m HBCYN  "+HBCYN"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("White esc[47;1m HBWHT   "+HBWHT"¡ö¡ö¡ö¡ö¡ö\n\n"NOR);

	write("Black esc[40m BBLK      "+BBLK"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Red esc[41m BRED      "+BRED"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Green esc[42m BGRN      "+BGRN"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Yellow esc[43m BYEL   "+BYEL"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Blue esc[44m BBLU       "+BBLU"¡ö¡ö¡ö¡ö¡ö"NOR+" ; Magenta esc[45m BMAG  "+BMAG"¡ö¡ö¡ö¡ö¡ö\n"NOR);
	write("Cyan esc[46m BCYN       "+BCYN"¡ö¡ö¡ö¡ö¡ö"NOR+" ; White esc[47m BCYN    "+BCYN"¡ö¡ö¡ö¡ö¡ö\n\n"NOR);

	write("Normal esc[2;37;0m NOR   "+NOR"¡ö¡ö¡ö¡ö¡ö\n"NOR);
return 1;
}
