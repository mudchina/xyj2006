//created 8-3-97 pickle
//副将

inherit NPC;

string weapon_file, skill, special_skill;
string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","樊","陈","祝","魏","蒋","沈","韩","杨", "刘","张","林","朱","欧阳","司马","慕容","诸葛" });
string *name_words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠",
        "孝","雄","益","添","金","辉","长","盛","胜","进","安","福","同","满",
        "富","万","龙","隆","祥","栋","国","亿","寿","思","霖","雷","鹏","平",
        "轼","甫","维","龄","桥","溪","声","谷","山","舟","岩","泉","游","逊", });
void determine_data()
{
  switch(random(5))
    {
        case 0:
        {
	    weapon_file="sword/changjian";
	    skill="sword";
	    special_skill="xiaofeng-sword";
	    break;
        }
        case 1:
        {
	    weapon_file="blade/blade";
	    skill="blade";
	    special_skill="wuhu-blade";
	    break;
        }
        case 2:
        {
	    weapon_file="mace/ironmace";
	    skill="mace";
	    special_skill="jinglei-mace";
	    break;
        }
        case 3:
        {
	    weapon_file="spear/changqiang";
	    skill="spear";
	    special_skill="bawang-qiang";
	    break;
        }
        case 4:
        {
	    weapon_file="axe/bigaxe";
	    skill="axe";
	    special_skill="sanban-axe";
	    break;
        }
    }
}
void create()
{
    string name;

    name = first_name[random(sizeof(first_name))];
    name += name_words[random(sizeof(name_words))];
    if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
  set_name(name, ({"fu jiang","fu","jiang", "general", "fujiang"}));
  set ("long", @LONG
他曾跟秦琼，程咬金，尉迟恭等人一齐在沙场上出生入死，靠着战功
一步步升到了副将。如今太平了，便练练兵，以防边疆有变。
LONG);
  determine_data();
  set("title", "副将");
  set("gender", "男性");
  set("age", 20+random(30));
  set("combat_exp", 300000+random(100000));
  set_skill(skill, 140);
  set_skill("dodge", 140);
  set_skill("parry", 140);
  set_skill("unarmed", 140);
  set_skill("force", 140);
  set_skill("changquan", 140);
  set_skill(special_skill, 140);
  set_skill("lengquan-force", 140);
  set_skill("yanxing-steps", 140);
  map_skill(skill, special_skill);
  map_skill("unarmed", "changquan");
  map_skill("dodge", "yanxing-steps");
  map_skill("parry", special_skill);
  set("max_sen", 400);
  set("max_kee", 700);
  set("max_force", 800);
  set("force", 1000);
  set("force_factor", 25);
  setup();
 
  carry_object("/d/obj/weapon/"+weapon_file)->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
int accept_fight(object me)
{
    command("enable dodge none");
    command("enable parry none");
    command("enable unarmed none");
    command("enable "+skill+" none");
    return 1;
}
int chat()
{
    object npc=this_object();

    if (query("sen")<query("max_sen")*20/100
      ||query("kee")<query("max_kee")*20/100)
    {
        command("enable dodge yanxing-steps");
        command("enable parry "+special_skill);
        command("enable unarmed changquan");
        command("enable "+skill+" "+special_skill);
        return 1;
    }
}
