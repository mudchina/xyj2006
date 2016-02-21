//Cracked by Roath
//  ÑýÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.9
//  /d/qujing/wuzhuang/shugan1.c

inherit ROOM;

void create ()
{
   set ("short", "Ê÷¸É");
   set ("long", @LONG
[32m
£®£®£®£®£®£®Ò»¸ö´Ö´ÖµÄÊ÷¸É£¬×ãÓÐÈý¸öºÏ±§ÆðÀ´ÄÇÃ´´Ö£®£®£®£®£®
[m
LONG);

   set("exits", 
   ([ //sizeof() == 4
        "up":   __DIR__"shugan2",
        "down": __DIR__"tree",
   ]));
   setup();
}
