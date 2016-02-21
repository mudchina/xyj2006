// created by snowcat

inherit ITEM;
#include "message.h"

void create()
{
  set_name("布娃娃", ({ "bu wawa", "buwawa", "wawa" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一只可爱逼真的小布娃娃。\n");
    set("unit", "只");
    set("value", 10000);
  }
  setup();
}

int init ()  
{   
  add_action ("do_setid", "setid");
  add_action ("do_setname", "setname");
  add_action ("do_nie", "nie");
  add_action ("do_shua", "shua");
  return 1;
}

int do_setid (string arg)
{
  object me = this_player();
  string name = this_object()->query("name");

  if (!wizardp(me))
    return 0;
  this_object()->set_name(name, ({ arg }) );
  return 1;
}

int do_setname (string arg)
{
  object me = this_player();

  if (!wizardp(me))
    return 0;

  this_object()->set("name",arg);
  this_object()->set("long","一"+this_object()->query("unit")+arg+"。\n");
  return 1;
}

int do_setunit (string arg)
{
  object me = this_player();

  if (!wizardp(me))
    return 0;

  this_object()->set("unit",arg);
  this_object()->set("long","一"+arg+this_object()->query("name")+"。\n");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_nie (string arg)
{
  string *dos = ({
    "用手指轻轻一捏",
    "轻轻捏了一下",
    "小心地捏一捏",
    "捏一捏",
    "轻碰了一下",
    "碰碰",
    "用手指点一点",
  });

  string *parts = ({
    "脑袋",
    "头发",
    "脸蛋",
    "胖腮帮",
    "嘴嘴",
    "小嘴唇",
    "耳朵",
    "眉心",
    "长睫毛",
    "鼻子",
    "小鼻尖",
    "下巴",
    "小脖子",
    "手",
    "胳膊",
    "腿",
    "脚",
    "肚肚",
    "小屁屁",
  });

  string *actions = ({
    "张开小口吱吱地叫了两声。",
    "张开嘴啊哟了一声。",
    "天真地呀呀叫出了声音。",
    "睁开大眼睛吧嗒吧嗒地眨了几下。",
    "睡意朦胧地慢慢睁开一对大眼睛。",
    "睁开眼睛，又满意地合上眼睛睡着了。",
    "摇了摇硕大的脑袋。",
    "东倒西歪地努力抬起大脑袋。",
    "认真地点点脑袋。",
    "瞪着大眼睛看着$N。",
    "呆呆地看着$N，吃吃地笑出声来。",
    "把胖胖的手指放到嘴里，一边吮吸一边看着$N。",
    "把脑袋往两边一转看了看，又抬头看看$N。",
    "害羞地把脑袋往$N怀里一钻。",
    "甜甜地把大脑袋贴在$N身上。",
    "皱了一皱月儿眉。",
    "小老头儿般地皱了一皱额头。",
    "高兴地把眼睛眯成一条缝。",
    "咧开小嘴哇地一声哭了出来。",
    "摆出一副可爱的小苦瓜脸。",
    "张开小嘴哭得喘不过气来。",
    "眯着眼睛，张开小嘴笑了出来。",
    "甜蜜一笑。",
    "笑呀笑呀笑呀。",
    "呀呀哟哟地唱了几句。",
    "高兴地唱了起来：咿噜啊哈哩……",
    "唱起摇篮曲：睡睡吧，乖乖耶……",
    "不高兴地噘了噘小嘴。",
    "满脸不高兴嘟囔着小嘴儿。",
    "噘起小嘴儿眼儿一翻扭过头去不理人了。",
    "用小手揪住$N的袖口。",
    "一把揪住$N的衣服死死不放。",
    "揪住$N的手眼巴巴地望着$N。",
    "伸出两条小腿胡乱踢了几下。",
    "抬起一条小腿伸在$N的脸上。",
    "高兴地拍打着两条小腿儿。",
    "扭了扭腰肢。",
    "撅了撅小屁屁。",
    "把小屁屁向$N一歪。",
    "笑了起来。",
    "咯咯咯笑个不停。",
    "搂着$N的脖子笑了起来。",
    "甜甜地一笑：叔叔阿姨，我要撒娇娇……",
    "天真地问：我撒个娇娇好不好呀？",
    "问$N：要是我撒个娇娇你是不是更喜欢我呀？",
    "突然开口说：咦，那个叔叔有小胡子，我怎么没有呢？",
    "说：哟，阿姨头发真长，挠在宝宝的脸上痒痒耶。",
    "问道：小宝宝我什么时候能长成大宝宝老宝宝？",
    "说道：阿姨，要不要听我唱支歌？",
    "说道：宝宝想唱支儿歌，哪一支呢？我想不起来哪支最好听的。",
    "嘟嘟囔囔地说：叔叔阿姨，我是个最好的小乖乖耶。",
    "一字一句地说：我最乖乖耶，叔叔阿姨只喜欢我一个小乖乖好吗？",
    "自言自语地说：我是小乖乖，小乖乖是我。",
    "细声细气地说：小乖乖我……想吃糖糖耶。",
    "说：往我嘴里放一颗糖糖好不好？",
    "说：叔叔阿姨能变魔术吗？变出糖糖来好不好？",
  });

  string str1 = "$N"+rdm(dos)+"$n的"+rdm(parts)+"。\n";  
  string str2 = "$n"+rdm(actions)+"\n";
  
  if (arg != this_object()->query("id"))
    return 0;

  this_object()->set("value", 0);
  remove_call_out ("delayed_action");
  call_out ("delayed_action",1,str1,this_player(),this_object());
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",3,str2,this_player(),this_object());
  return 1;
}

int do_shua (string arg)
{
  object me = this_object();
  object who;
  string my_name = me->query("name");
  string *dos = ({
    "飞快地从$N手中跑下来，爬到$n的",
    "从$N身上滑下来，蹿到$n的",
    "从$N手中使劲往$n身上一跳，贴在$n的",
    "朝$N点点头，一转身扒在$n的",
    "会意地爬到$n的",
    "老练地扑到$n的",
    "鬼鬼祟祟地蹦到$n的",
    "一个弹跳扑到$n的",
    "跳上$n的",
    "呼地一跳，跃在$n的",
    "一个小飞身跃在$n的",
    "身子一闪，已站在$n的",
    "巧巧地一翻身，抓在$n的",
    "机灵地抓在$n的",
  });

  string *parts = ({
    "后脑勺",
    "扁脑门",
    "乱头发",
    "秃顶",
    "水泡眼",
    "老鼠眼",
    "腮帮",
    "黄脸蛋",
    "厚嘴唇",
    "咧开的嘴巴",
    "肥耳朵",
    "大暴牙",
    "酒糟鼻子",
    "宽鼻梁",
    "肥下巴",
    "斜酒窝",
    "歪脖子",
    "瘦喉结",
    "塌肩膀",
    "鸡胸",
    "短拇指",
    "肥掌",
    "左手",
    "右手",
    "胳膊肘",
    "瘦排骨",
    "小腿",
    "短腿",
    "大腿",
    "火柴棍大腿",
    "罗圈腿",
    "哈吧腿",
    "水桶腰",
    "南瓜腰",
    "水蛇腰",
    "水萝卜腰",
    "麻花腰",
    "搓板儿背",
    "脚后跟",
    "裹脚背",
    "大脚趾",
    "细脚肘",
    "大肚皮",
    "啤酒肥肚",
    "瘪肚皮",
    "驼背",
    "肥臀",
    "臀尖",
  });

  string *actions = ({
    "不客气地迅速尿了一小滩尿。",
    "端起小水枪就狂浇一气。",
    "呸了一小口。",
    "吐出一小堆粘粘的口香糖渣。",
    "张口就舔了几口。",
    "将$n舔得死去活来。",
    "张开小嘴咬了一口。",
    "张开小嘴咬住$n死死不放。",
    "咬下一小砣肉。",
    "咬下一大块疙瘩肉。",
    "咬得$n捶胸顿足哭爹喊娘。",
    "咬出两排红牙印儿。",
    "咬出一大块瘀血紫疤。",
    "揪下一撮毛。",
    "揪下一层老皮。",
    "扯住一撮细毛不放。",
    "硬是扯出一个血囊葫芦。",
    "吧嗒吧嗒使劲捶了几拳。",
    "捶出一个大囊肿。",
    "胡乱踢了几下。",
    "踢得$n上吐下泄。",
    "砰地一声踢中要害。",
    "踢得$n直翻白眼。",
    "用大脑袋轰地一撞。",
    "用小指扎出几个绣花窟窿。",
    "使劲地抓出五道血痕。",
    "抓出五串水泡。",
    "伸出双手玩命地一掐。",
    "咬牙切齿地掐住$n的人中。",
    "伸出手掐出好大一个肿块。",
    "拽着悠秋千。",
    "啪啪左右开弓扇了十几下。",
    "扇了个两面红。",
    "毫不客气地挠起痒痒儿。",
    "挠出一大片粉头痱子。",
    "用小手指抠出一小肿疱。",
    "用手指抠出一沙疮。",
    "掏出一块红疤。",
    "抓出一大片青春美丽豆。",
  });

  string *returns = ({
    "然后跑回$N身上。",
    "然后悄悄地回到$N手中。",
    "再回头一本正经地爬到$N身上。",
    "再纵身跃回到$N手中。",
    "再回头一跳，跃到$N身上。",
    "然后高兴地回到$N手中。",
    "然后得意地钻回$N身上。",
    "然后十分满意地钻回$N手中。",
    "然后兴奋地蹦回$N身上。",
    "然后欣喜若狂地蹦回$N手中。",
  });

  string str1 = my_name+rdm(dos)+rdm(parts)+"上，"+rdm(actions)+"\n";
  
  if (! arg)
    return 0;

  who = present(arg,environment(this_player()));
  if (! who)
    return notify_fail ("耍谁？\n");

  this_object()->set("value", 0);
  message_vision ("$N向"+my_name+
                  "使了一个眼色，然后若无其事地看了$n一眼。\n",
                  this_player(),who);
  remove_call_out ("delayed_action");
  call_out ("delayed_action",3,str1,this_player(),who);
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",4,rdm(returns)+"\n",
            this_player(),who);
  return 1;
}

void delayed_action (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}

void delayed_reaction (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}
