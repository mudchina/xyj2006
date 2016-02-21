//Cracked by Roath
//tanghulu happ@yszz
inherit ROOM;
void create ()
{
        set ("short", "±ùÌÇºùÂ«µê");
        set ("long", @LONG

  Õâ¼Ò±ùÌÇºùÂ«µê¿ÉÊÇÀÏ×ÖºÅÁË£¬×Ô´ÓÈı¹ú²Ü²Ù³Ô¹ıÕâÎ»Íõ´óÉ©
µÄ×æÏÈÖÆµÄÌÇºùÂ«Ò»Ö±°®²»ÊÍÊÖ£¬Èç½ñÊ±´ú±äÇ¨£¬µ«µ±ÄêµÄÄÇ¿é
ÕĞÅÆ»¹ÊÇÏóÍù³£Ò»Ñù¡£
[1;33m              ©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©·
              ©§     Õı×Ú±ùÌÇºùÂ«     ©§
              ©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿[m
LONG);

        set("exits",
        ([ //sizeof() == 4
            "north" : __DIR__"sibei-w2",
      ]));
        set("objects", ([
            __DIR__"npc/wang": 1,
                        ]));
        set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
 replace_program(ROOM);
}
