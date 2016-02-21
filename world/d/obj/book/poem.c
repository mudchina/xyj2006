// poem.c

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("〖太白自选集〗", ({"poem","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long",
	"这本书大概有两三百页，蓝底白字的封面上龙飞凤舞地写着“太白自选集”。\n");
        set("material", "paper");
        set("value", 500);   
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	string *poem = ({
		"花间一壶酒，独酌无相亲。",
		"停杯投箸不能食，拔剑四顾心茫然。",
		"抽刀断水水更流，举杯销愁愁更愁。",
		"十四为君妇，羞颜未尝开。",
		"春风不相识，何事入罗帏。",
		"君不见，黄河之水天上来，奔流到海不复回。",
		"云想衣裳花想容，春风拂槛露华浓。",
		"名花倾国两相欢，常得君王带笑看。",
		"噫吁戏，危乎高哉！蜀道之难，难于上青天。",
		"明月出天山，苍茫云海间。",
		"我醉欲眠卿且去，明朝有意抱琴来。",
		"美人一笑褰珠箔，遥指红楼是妾家。",
		"五岳寻仙不辞远，一生好入名山游。",
		"安能摧眉折腰事权贵，使我不得开心颜。",
		"一枝红艳露凝香，云雨巫山枉断肠。",
		});
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("书要拿起来读。\n");
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有闲情逸致吟诗...\n");
   	if( me->is_fighting() )
        		return notify_fail("太风雅了吧？打架时还吟诗...\n");
	
	if( (int)me->query_skill("literate",1)<100 )
		return notify_fail("你照着诗集摇头晃脑地哼了几句，不过没明白是啥意思。\n");
	if( (int)me->query_skill("literate",1)>240 )
		return notify_fail("你在文字方面已经很有造诣，这本书不会让你长进多少。\n");

	sen_cost = 20 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

        gain = (int)me->query_skill("literate", 1)+(int)me->query("int")+1;
	me->improve_skill("literate", gain);

    	message_vision("$N拿着本诗集摇头晃脑地吟道：" + poem[random(sizeof(poem))] + "\n", me);
		
	return 1;
}

