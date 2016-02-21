// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第一宫：白羊宫");
        set ("long", @LONG

    特寒里亚国王阿塔玛斯和王妃涅佩拉结婚，两人生了一对双胞胎，但国王却和特
贝的公主伊诺娃有段婚外情，将涅佩拉王妃赶出宫，而迎立诺娃为新妃。当伊诺娃王
妃有了自己的孩子后，乃决定要杀死前涅佩拉王妃所留下的唯一双胞胎，(哥哥是普里
克思，妹妹是赫雷)。她收买占卜师向国王告状：若不将前王妃所生的孩子送给宙斯当
祭品，众神将大怒，则今年将闹饥荒。涅佩拉知道后就向宙斯求救，于是宙斯就派天
上的黄金牡羊去载这两兄妹至天空彼方。因速度太快，妹妹跌落大海，牡羊就一边回
头看妹妹，一边守护着哥哥，而形成现今的牡羊座。

LONG);


        set("exits", ([
        "northup"    :       __DIR__"by2jn1",
            "eastdown"  :       __DIR__"toby2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baiyang" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
           
		  if (me->query_temp("12gong/cike") == "done")
	{if ( present("mu") && dir == "northup" )
           return notify_fail("穆先生冷笑一声：先过我这关再说！\n");
	}
		  
		  if (me->query("12gong/baiyang") != "done")
	{
			  if ( present("mu") && dir == "northup" )
			  return notify_fail("穆先生微微一笑说道: 既然来了何必急着走?\n");
	}
	     
		 return ::valid_leave(me, dir);
}



void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
