inherit ITEM;

//int query_autoload () { return 1; }

void create()
{
        set_name("描龙玉佩", ({"yu pei", "pei"}));
        set_weight(100);
           set("unit", "枚");
           set("long", "一枚玉佩，上面还雕着花，写着字。\n");
          set("no_sell", 1);
	  set("jiebai", 0);
	  set("value", 5000);
	setup();
}

void init()
{
add_action("do_jiebai", "jiebai");
}

int do_jiebai(string arg)
{
	object ob, obj, me=this_player();

	if (!arg) return notify_fail("你要和谁结拜？\n");

	obj = present(arg, environment(me));
	if (!objectp(obj)) return notify_fail("\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");

	if( obj->query_temp("pending/jiebai") != me) {
		message_vision("\n$N对着$n说道："
			+ RANK_D->query_self(me)+ me->name() 
			+ "，欲与"
			+ RANK_D->query_respect(obj) 
			+ "结为异姓" 
			+ (obj->query("gender")=="男性" ? "兄":"姐" )
			+ (me->query("gender")=="男性"? "弟" : "妹")
			+ "，不知" + RANK_D->query_respect(obj)
			+ "意下如何？\n\n", me, obj);
		me->set_temp("pending/jiebai", obj);
		return 1;
		}

	obj->delete_temp("pending/jiebai");
	message_vision("$N对着$n说道："
		+ RANK_D->query_self(me)+ me->name()
		+ "，愿与"
		+ RANK_D->query_respect(obj)
		+ "结为异姓" 
                + (obj->query("gender")=="男性" ? "兄":"姐")
                + (me->query("gender")=="男性"? "弟" : "妹")
		+ "！\n\n", me, obj);

	message_vision("$N和$n跪下来，朝着天地叩了九叩，焚香盟誓曰：\n“念"
		+ obj->query("name") + "、" + me->query("name")
		+ "，虽非骨肉，既结为"
		+ (obj->query("gender")=="男性" ? "兄":"姐")
                + (me->query("gender")=="男性"? "弟" : "妹")
		+ "，则同心协力，救困扶危；\n"
		+ "上报国家，下安黎庶；不求同年同月同日生，只愿同年同月同日死。\n"
		+ "皇天后土，实鉴此心。背义忘恩，天人共戮！”\n\n", me, obj);

	if (query("jiebai")) return 1;
	set("jiebai", 1);
	set("long", "\n一枚铜牌，上书：\n" + "君子之交淡如水\n\t" +
		obj->query("name") + "、" + me->query("name") + "共识\n");

	ob=present("yu pei", obj);
	if (!ob) return 1;
	if (ob->query("jiebai")) return 1;
	ob->set("jiebai", 1);
	ob->set("long", "\n一枚描龙玉佩，上书：\n" + "君子之交淡如水\n\t" +
		me->query("name") + "、" + obj->query("name") + "共识\n");

	return 1;

}
