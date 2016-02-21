//Cracked by Roath

//  ÑıÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/shulin1.c

inherit ROOM;

void create ()
{
  set ("short", "[33mÊ÷ÁÖ[m");
  set ("long", @LONG

ÕâÀï¾¡ÊÇĞ©²ÎÌì´óÊ÷£¬ÄãÒ»×ß½øÀ´£¬¾ÍÃÔÊ§ÁË·½Ïò£¬Ö»¾õµÃËÄÖÜÖ»ÊÇ
Ò»Æ¬Ä«ÂÌ£¬ÖÜÎ§¾°É«¶¼ÊÇÒ»ÑùµÄ¡£

LONG);

  set("exits", ([
        "north":__DIR__"shulin6",
        "east" : __DIR__"shulin8",
        "west" : __DIR__"shulin4",
        "south": __DIR__"shulin4",
      ]));
  setup();
}
void init()
{

        if( present("zhu guai 2") )
        {
        remove_call_out("des");
        call_out("des",1);
        }
}
void des()
{
        object pig;
        pig=find_living("zhu guai");
        destruct(pig);
}
