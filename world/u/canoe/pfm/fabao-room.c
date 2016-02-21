// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//self-made fabao room

#include <ansi.h>
#include <weapon.h>
#include <armor.h>
#include <login.h>

inherit ROOM;

#define MAX_FABAO   3

int  do_sm();
int  do_dispose(string arg);
int  do_upgrade(string arg);
int  do_list();
int  do_cost(string arg);

void get_type(string arg, object ob);
void get_subtype(string arg, object ob);
void get_id(string arg, object ob);
void get_name(string arg, object ob);
void get_desc(string arg, object ob);
void get_unit(string arg, object ob);
void build_weapon(object ob);
void build_armor(object ob);
int check_legal_name(string name, int max_len);
int check_legal_id(string name);
void confirm_dispose(string arg, object ob, object fabao_ob);

void init()
{
    add_action("do_sm", "make_fabao");
    add_action("do_dispose", "dispose");
    add_action("do_list", "list");
    add_action("do_cost", "cost");
    add_action("do_upgrade", "upgrade");
    add_action("do_change_name", "change_name");
    add_action("do_change_id", "change_id");
    add_action("do_change_desc", "change_desc");
    add_action("do_change_unit", "change_unit");

   seteuid(getuid());
}

void create ()
{
        set ("short", "女娲补天处");
        set ("long", @LONG

这里是一片开阔地。地上铺满了一堆又一堆奇形怪状色彩斑斓的
残岩碎石，在雪色映照下溢彩流光。边上一块大石上刻着几行大
字：

     昆仑绝处
     女娲补天
     彩石未尽
     遗福後人

底下还密密麻麻地刻了一篇小字(words)，隔远了也看不清说的是
什么。
LONG);

        set("item_desc", ([ "words" : 
             "make_fabao     炼制法宝\n" +
             "dispose        注消法宝\n" +
             "list           列举可制法宝种类\n" +
             "upgrade        法宝升级\n" +
             "cost 法宝      法宝炼制及升级可能费用\n" +
             "change_name    给法宝改名\n" +
             "change_id      给法宝改代号\n" +
             "change_desc    给法宝改描述\n" +
             "change_unit    给法宝改单位名称\n\n" +
             HIY+"升级暂行办法：\n"+NOR+
             "　　每五次升级加一个星，最高为五星。\n"+
             "　　代价以加一星为计算标准。比如升两星要\n" + 
             "　　100000武学，升三星要500000武学，那么升两\n" +
             "　　星后，每次升级就需要 80000武学。\n", ]));

        set("exits", 
        ([ //sizeof() == 1 
                "east" : __DIR__"fabao-road2",
"up" : __DIR__"butian",
 ]));
set("objects", 
([ //sizeof() == 1
   __DIR__"npc/nuwa" : 1,
  ]));


   set("no_fight", 1);
   set("no_magic", 1);

    setup();
}

int do_sm()
{
    object me = this_player();
   int  fabao_num;
   
   if( me->query("balance") < 500000 )
      return notify_fail("做法宝费用太高，还是先去发财吧。\n");
      
   if( me->query("combat_exp") < 20000)
     return notify_fail("你的道行不够，不能自造法宝。\n");
   
   if( me->query("max_force") < 300 )
     return notify_fail("你的内力不够，不能自造法宝。\n");
     
   if( me->query("max_mana") < 300)
     return notify_fail("你的法力不够，不能自造法宝。\n");
   
   if( me->query("force") < (me->query("max_force")+100) )
     return notify_fail("你的真气不足，不能自造法宝。\n");
   
   if( me->query("mana") < (me->query("max_mana")+100) )
     return notify_fail("你的目前法力不足，不能自造法宝。\n");
   
//   if( me->query("kee") != me->query("max_kee") ||
//       me->query("sen") != me->query("max_sen") ) 
//     return notify_fail("你的精气不足，不能自造法宝。\n");

    fabao_num = 0;     
   if( me->query("fabao/weapon") )     fabao_num++;
   if( me->query("fabao/armor1") )     fabao_num++;
   if( me->query("fabao/armor2") )     fabao_num++;
   
   if( fabao_num >= MAX_FABAO )
     return notify_fail("你不能再炼制法宝了，请用 dispose 注消不要的法宝。\n");
     
   write("您要造哪类法宝：\n");
   if( !me->query("fabao/weapon") )
     write("w. 武器\n");
   if( !me->query("fabao/armor1") || !me->query("fabao/armor2") )
     write("a. 防具\n");
   write("o. 其他(暂缺)\n");

   seteuid(getuid());
   // Other kinds of fabao can be added too.. if there is somefile
   // we can use as a default object.
   write("请选择：(q 键取消)");
   input_to( (: get_type :), me );
   
   return 1;   
}

void get_type(string arg, object ob)
{
   if( arg == "q" || arg == "Q" )
      return;

   if( (arg != "w" || ob->query("fabao/weapon"))
     && (arg != "a" || ( ob->query("fabao/armor1")
     && ob->query("fabao/armor2") )) )   {
     write("您要造哪类法宝：\n");
     if( !ob->query("fabao/weapon") )
        write("w. 武器\n");
     if( !ob->query("fabao/armor1") || !ob->query("fabao/armor2") )
        write("a. 防具\n");
       write("o. 其他(暂缺)\n");
       write("请选择：(q 键取消)");
     input_to( (: get_type :), ob );
     return;
   }

   if( arg == "w" )    {
     ob->set_temp("fabao_type", "weapon");
     write("\n");
     write("可选择武器种类：\n");
     write("1. 斧  2. 刀  3. 叉  4. 锤  5. 锏  6. 枪\n");
     write("7. 杖  8. 棒  9. 剑  10. 鞭\n");
       write("请选择：(q 键取消)");
   }
   else if( arg == "a" )   {
     ob->set_temp("fabao_type", "armor");
     write("\n");
     write("可选择防具种类：\n");
     write("1. 甲  2. 鞋  3. 衣服  4. 指套  5. 护掌  6. 头罩\n");
     write("7. 脖套  8. 盾  9. 披风  10. 护腕  11. 腰带\n");
       write("请选择：(q 键取消)");
   }
   input_to( (: get_subtype :), ob);
}

void get_subtype(string arg, object ob)
{
    int  order;
   string fabao_type = ob->query_temp("fabao_type");
   
   if( arg == "q" || arg == "Q" )    return;

    sscanf(arg, "%d", order);
    
   if( (fabao_type == "weapon" && order <= 0 && order > 10) ||
     (fabao_type == "armor" && order <= 0 && order > 11) )  {
     if( arg == "w" )    {
        fabao_type = "weapon";
        write("\n");
        write("可选择武器种类：\n");
        write("1. 斧  2. 刀  3. 叉  4. 锤  5. 锏  6. 枪\n");
        write("7. 杖  8. 棒  9. 剑  10. 鞭\n");
           write("请选择：(q 键取消)");
     }
     else if( arg == "a" )   {
        fabao_type = "armor";   
        write("\n");
        write("可选择防具种类：\n");
        write("1. 甲  2. 鞋  3. 衣服  4. 指套  5. 护掌  6. 头罩\n");
        write("7. 脖套  8. 盾  9. 披风  10. 护腕  11. 腰带\n");
           write("请选择：(q 键取消)");
     }
     ob->set_temp("fabao_type", fabao_type);
     input_to( (: get_subtype :), ob);
     return;
   }
   
   ob->set_temp("fabao_subtype",  order);

   write("\n");
   write("请设定英文 id ：");
   input_to( (: get_id :), ob ); 
}


int check_legal_id(string id)
{
   int i;
   string   *legalid;
   
   i = strlen(id);
    if( (strlen(id) < 3) || (strlen(id) > 20 ) ) {
     write("对不起，英文 id 必须是 3 到 20 个英文字母。\n");
     return 0;
    }
    while(i--)
       if( id[i] != ' ' && (id[i]<'a' || id[i]>'z') )  {
         write("对不起，英文 id 只能用英文字母。\n");
         return 0;
       }
    
    legalid = explode(read_file(BANNED_ID), "\n");
    for(i=0; i<sizeof(legalid); i++)   {
       if( id == legalid[i] )   {
         write("对不起，这种 id 会造成其他人的困扰。\n");
         return 0;
       }
    }
    
    return 1;
}


int check_legal_name(string name, int max_len)
{
   int i;
   string   *legalname;     //not implemented..may add later
   
   i = strlen(name);
    if( (strlen(name) < 2) || (strlen(name) > max_len ) ) {
       write( sprintf("对不起，法宝中文字必须是 1 到 %d 个中文字。\n",
        max_len/2) );
     return 0;
    }
    while(i--)   {
       if( name[i]<=' ' )   {
         write("对不起，法宝中文字不能用控制字元。\n");
         return 0;
       }
       if( i%2==0 && !is_chinese(name[i..<0]) )  {
         write("对不起，请您用「中文」给法宝取名字。\n");
         return 0;
       }
    }
   
    return 1; 
}


void get_id(string arg, object ob)
{
   arg = lower_case(arg);
   if( !check_legal_id(arg) )   {
     write("请设定英文 id ：");
     input_to( (: get_id :), ob ); 
     return;
   }

   arg = replace_string(arg, " ", "_");   
   ob->set_temp("fabao_id",arg);
   
   write("\n");
   write("请设定中文名：(可加颜色)");
   input_to( (: get_name :), ob);
}

void get_name(string arg, object ob)
{
   string  arg_old;
   
   arg += "$NOR$";
   arg_old = arg;
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");

   if( !check_legal_name(arg, 12) )  {
        write("请设定中文名：(可加颜色)");
     input_to( (: get_name :), ob);
     return;
   }

   arg = arg_old;

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
   
   ob->set_temp("fabao_name", arg + NOR);
   
   write("\n");
   write("请描述法宝：");
   input_to( (: get_desc :), ob);
}

void get_desc(string arg, object ob)
{
   if( !check_legal_name(arg, 60) )  {
     write("请描述法宝：");
     input_to( (: get_desc :), ob);
     return;
   }

   ob->set_temp("fabao_desc",  arg);
   
   write("\n");
   write("法宝用量词：(Return for default)");
   input_to( (: get_unit :), ob);
}


void get_unit(string arg, object ob)
{
   string fabao_unit, fabao_type;

    if( arg == "" )
       fabao_unit = "";
   else if( !check_legal_name(arg, 2) )  {
       write("法宝用量词：(Return for defult)");
      input_to( (: get_unit :), ob);
      return;
    }
    else
       fabao_unit = arg; 
   
   fabao_type = ob->query_temp("fabao_type");
   ob->set_temp("fabao_unit", fabao_unit);
   if( fabao_type == "weapon" )
     build_weapon(ob);   
   else if( fabao_type == "armor" )
     build_armor(ob);   
   // may have more later
}

void build_weapon(object ob)
{
   object newob;
   string weapon_dir, ob_file;
   string *id_list, *t_list;
   int rev;
   int    fabao_subtype = ob->query_temp("fabao_subtype");
   string fabao_id = ob->query_temp("fabao_id");
   string fabao_name = ob->query_temp("fabao_name");
   string fabao_desc = ob->query_temp("fabao_desc");
   string fabao_unit = ob->query_temp("fabao_unit");
   
   newob = new("/obj/fabao");
   if(!newob)
     return;
     
   seteuid(fabao_id);
   rev = export_uid(newob);
   seteuid(getuid());

   newob->set("value", 1);
   newob->set("no_get", 1);   
   newob->set("no_give", 1);   
   newob->set("no_sell", 1);   
   newob->set("no_drop", 1);   
   newob->set("no_put", 1);   
   newob->set("no_steal", 1);
   
   weapon_dir = "/d/obj/weapon/";
   newob->set("weapon_prop/damage", 10);
   newob->set("flag", TWO_HANDED);
   newob->set("weight", 1000);
   switch( fabao_subtype )   {
     case 1:
        ob_file = weapon_dir + "axe/bigaxe";
        break;
     case 2:
        ob_file = weapon_dir + "blade/blade";
        break;
     case 3:
        ob_file = weapon_dir + "fork/gangcha";
        break;
     case 4:
        ob_file = weapon_dir + "hammer/hammer";
        break;
     case 5:
        ob_file = weapon_dir + "mace/ironmace";
        break;
     case 6:
        ob_file = weapon_dir + "spear/gangqiang";
        break;
     case 7:
        ob_file = weapon_dir + "staff/muzhang";
        break;
     case 8:
        ob_file = weapon_dir + "stick/qimeigun";
        break;
     case 9:
        ob_file = weapon_dir + "sword/changjian";
        break;
     case 10:
        ob_file = weapon_dir + "whip/pibian";
        break;
   }

   newob->set_default_object( ob_file );
   
   newob->set("long", fabao_desc);
   newob->set("stars/damage", 1);
   newob->set("upgraded/damage", 0);
   if( fabao_unit != "" )
      newob->set("unit", fabao_unit);
   id_list = ({ fabao_id });
   t_list = explode( fabao_id, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   newob->set_name( fabao_name, id_list ); 

   // set owner of fabao
   newob->set("owner_id", getuid(ob));
   newob->set("series_no", "1");
   newob->set("default_file", ob_file);


    newob->save();   

   //ob->add("max_force", -50);
   //ob->add("max_mana", -50);
   ob->add("force", -200);
   ob->add("mana", -200);
   ob->add("balance", -500000);

   ob->set("fabao/weapon",  newob->query("series_no"));

   newob->setup();
   if( !newob->move(ob) )
      newob->move(environment(ob));
   ob->save();
   
   write("法宝炼制成功。\n");

   return;
}

void build_armor(object ob)
{
   object   newob;
   string   armor_dir, ob_file;
   string   *id_list, *t_list;
   int     rev;
   string  fabao_id = ob->query_temp("fabao_id");
   string  fabao_name = ob->query_temp("fabao_name");
   string  fabao_desc = ob->query_temp("fabao_desc");
   string  fabao_unit = ob->query_temp("fabao_unit");
   int     fabao_subtype = ob->query_temp("fabao_subtype");

   newob = new("/obj/fabao");
   if(!newob)
     return;
   
   seteuid(fabao_id);
   rev = export_uid(newob);
   seteuid(getuid());

   newob->set("value", 1);
   newob->set("no_get", 1);   
   newob->set("no_sell", 1);   
   newob->set("no_give", 1);   
   newob->set("no_drop", 1);   
   newob->set("no_put", 1);   

   armor_dir = "/d/obj/";
   newob->set("armor_prop/armor", 5);     
   newob->set("armor_prop/dodge", 0);     
   newob->set("armor_prop/spells", 0);
   newob->set("weight", 1000);
   // anything else need to be set?
   
   switch( fabao_subtype )   {
   
   // Add ob_file if you can find the same kind of file
     case 1:
        ob_file = armor_dir + "armor/tenjia";
        break;
     case 2:
        ob_file = armor_dir + "cloth/buxie";
        break;
     case 3:
        ob_file = armor_dir + "cloth/linen";
        break;
     case 4:
        ob_file = armor_dir + "cloth/ring";
        break;
     case 5:
        ob_file = armor_dir + "cloth/gloves";
        break;
     case 6:
        ob_file = armor_dir + "cloth/hat";
        break;
     case 7:
        ob_file = armor_dir + "cloth/necklace";
        break;
     case 8:
        ob_file = armor_dir + "armor/niupi";
        break;
     case 9:
        ob_file = armor_dir + "cloth/surcoat";
        break;
     case 10:
        ob_file = armor_dir + "cloth/wrists";
        break;
     case 11:
        ob_file = armor_dir + "cloth/belt";
        break;
   }
   
   newob->set_default_object( ob_file );
   
   newob->set("long", fabao_desc);
   newob->set("stars/dodge", 1);
   newob->set("stars/armor", 1);
   newob->set("stars/armor_vs_force", 1);
   newob->set("stars/spells", 1);
   newob->set("stars/armor_vs_spells", 1);
   newob->set("upgraded/dodge", 0);
   newob->set("upgraded/armor", 0);
   newob->set("upgraded/armor_vs_force", 0);
   newob->set("upgraded/spells", 0);
   newob->set("upgraded/armor_vs_spells", 0);
   if( fabao_unit != "" )
      newob->set("unit", fabao_unit);
   id_list = ({ fabao_id });
   t_list = explode( fabao_id, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   newob->set_name( fabao_name, id_list ); 

   // set owner of fabao
   newob->set("owner_id", getuid(ob));
   if( !ob->query("fabao/armor1") )
     newob->set("series_no", "2");
   else if( !ob->query("fabao/armor2") )
     newob->set("series_no", "3");
   newob->set("default_file", ob_file);

    newob->save();   

   //ob->add("max_force", -50);
   //ob->add("max_mana", -50);
   ob->add("force", -200);
   ob->add("mana", -200);
   ob->add("balance", -500000);
   
   if( !ob->query("fabao/armor1") )
     ob->set("fabao/armor1",  newob->query("series_no"));
   else if( !ob->query("fabao/armor2") )
     ob->set("fabao/armor2",  newob->query("series_no"));
   
   newob->setup();
   if( !newob->move(ob) )
      newob->move(environment(ob));
   ob->save();

   write("法宝炼制成功。\n");
   
   return;
}

int  do_dispose(string arg)
{
   object ob = this_player();
   object fabao_ob;
  
   if( !arg || arg == "" )
     return notify_fail("你要消除什么法宝？\n");

   if( !objectp(fabao_ob=present(arg, ob)) )
      return notify_fail("你身上没有这样东西啊。\n");
      
   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");
      
   write("你确定要毁灭该法宝吗？(y/n)");
   input_to( (: confirm_dispose :), ob, fabao_ob); 
   return 1;
}

void confirm_dispose(string arg, object ob, object fabao_ob)
{
   mapping  fabao_list;
   string*  names;
   int      i;

   if( arg == "y" || arg == "Y" )  {
     fabao_list = ob->query("fabao");
     if( !mapp(fabao_list) )     return;
     names = keys(fabao_list);
     for(i=0; i<sizeof(names); i++)  {
      if( fabao_list[names[i]] == fabao_ob->query("series_no") )  {
        //seteuid(getuid(ob));
        //rm( fabao_ob->query_save_file() + __SAVE_EXTENSION__ );
        ob->delete("fabao/"+names[i]);
        destruct( fabao_ob );
        write("法宝被毁弃了。\n");
        break;
      }
     }
   }

   return;
}

int  do_list()
{
    write("目前可造法宝种类有：\n");   
    write("w. 武器类：\n");
   write("       斧  刀  叉  锤  锏  枪\n");
   write("       杖  棒  剑  鞭\n\n");
   write("a. 护具类：\n");
   write("       护甲  鞋  衣服  指套  护掌  头罩\n");
   write("       脖套  盾  披风  护腕   腰带\n\n");
   write("目前法宝可升级种类：\n");
    write("w. 武器：\n");
   write("       加伤害力\n\n");
   write("a. 护具类：\n");
   write("       加防御力\n");
   write("       加抵抗力\n");
   write("       加内功抵抗力\n");
   write("       加魔法攻击力\n");
   write("       加魔法抵抗力\n");

   return 1;   
}

int do_cost(string arg)
{
   object fabao_ob, me=this_player();
   int i, damage_stars, dodge_stars, armor_stars, force_stars;
   int spells_stars, vs_spells_stars;
   
   if( !arg || arg == "" )  {
      write("制造法宝需要五十两黄金，两百点真气和魔力，\n");
      write("并且道行必须在二十年以上，最大内力法力都必\n");
      write("须在 300以上。例如你的内力是 1500/1200，那\n");
      write("高出来的300就是真气，魔力类似。\n");
      return 1;
   }
  
   if( !objectp(fabao_ob=present(arg, me)) )
      return notify_fail("你身上没有这样东西啊。\n");
      
   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");
      
   if( fabao_ob->query("series_no") == "1" )  {
      write("法宝等级：    " + HIR);
      damage_stars = fabao_ob->query("stars/damage");
      for(i=0; i<damage_stars; i++)
         write("★");
      write(NOR + "\n");
      write(HIG+"伤害力" + NOR+ "(damage)升级需要：\n");
      switch(damage_stars)  {
         case 1:  write("    道行一百年以上\n");
                  write("    内力五百以上\n");
                  write("    消耗最大内力五十点\n");
                  write("    消耗道行一年\n");
                  break;
         case 2:  write("    道行五百年以上\n");
                  write("    内力一千以上\n");
                  write("    消耗最大内力一百点\n");
                  write("    消耗道行十年\n");
                  break;
         case 3:  write("    道行一千年以上\n");
                  write("    内力一千五以上\n");
                  write("    消耗最大内力一百五十点\n");
                  write("    消耗道行二十年\n");
                  break;
         case 4:  write("    道行一千五百年以上\n");
                  write("    内力两千以上\n");
                  write("    消耗最大内力两百点\n");
                  write("    消耗道行五十年\n");
                  break;
         case 5:  write("你的法宝"+HIG+"伤害力"+NOR+"已经不能再升级了。\n");
      }
   }
   else if( fabao_ob->query("series_no") == "2"  ||
   fabao_ob->query("series_no") == "3" )  {
      dodge_stars = fabao_ob->query("stars/dodge");
      armor_stars = fabao_ob->query("stars/armor");
      force_stars = fabao_ob->query("stars/armor_vs_force");
      spells_stars = fabao_ob->query("stars/spells");
      vs_spells_stars = fabao_ob->query("stars/armor_vs_spells");
      write("法宝等级：\n");
      write("    " + HIY+"防御力        "+HIR);
      for(i=0; i<dodge_stars; i++)
         write("★");
      for(i=dodge_stars; i<5; i++)
         write("　");
      write("    " + HIB+"抵抗力        "+HIR);
      for(i=0; i<armor_stars; i++)
         write("★");
      write("\n"); 
      write("    " + HIM+"内功抵抗力    "+HIR);
      for(i=0; i<force_stars; i++)
         write("★");
      for(i=force_stars; i<5; i++)
         write("　");
      write("    " + HIC+"魔法攻击力    "+HIR);
      for(i=0; i<spells_stars; i++)
         write("★");
      write("\n"); 
      write("    " + HIW+"魔法抵抗力    "+HIR);
      for(i=0; i<vs_spells_stars; i++)
         write("★");
      write(NOR+"\n"); 
      
      switch( dodge_stars )   {
         case 1:  write(HIY+"防御力" + NOR+ "(dodge)升级需要：\n");
                  write("    道行两百年以上\n");
                  write("    消耗道行五年\n");
                  break;
         case 2:  write(HIY+"防御力" + NOR+ "(dodge)升级需要：\n");
                  write("    道行五百年以上\n");
                  write("    消耗道行二十年\n");
                  break;
         case 3:  write(HIY+"防御力" + NOR+ "(dodge)升级需要：\n");
                  write("    道行一千年以上\n");
                  write("    消耗道行五十年\n");
                  break;
         case 4:  write(HIY+"防御力" + NOR+ "(dodge)升级需要：\n");
                  write("    道行一千五百年以上\n");
                  write("    消耗道行一百年\n");
                  break;
         case 5:  write("你的法宝"+HIY+"防御力"+NOR+"已经不能再升级了。\n");
      }
      switch( armor_stars )   {
         case 1:  write(HIB+"抵抗力" + NOR+ "(armor)升级需要：\n");
                  write("    道行一百年以上\n");
                  write("    内力五百以上\n");
                  write("    消耗最大内力五十点\n");
                  write("    消耗道行一年\n");
                  break;
         case 2:  write(HIB+"抵抗力" + NOR+ "(armor)升级需要：\n");
                  write("    道行五百年以上\n");
                  write("    内力一千以上\n");
                  write("    消耗最大内力一百点\n");
                  write("    消耗道行五年\n");
                  break;
         case 3:  write(HIB+"抵抗力" + NOR+ "(armor)升级需要：\n");
                  write("    道行一千年以上\n");
                  write("    内力一千五以上\n");
                  write("    消耗最大内力一百五十点\n");
                  write("    消耗道行二十年\n");
                  break;
         case 4:  write(HIB+"抵抗力" + NOR+ "(armor)升级需要：\n");
                  write("    道行一千五百年以上\n");
                  write("    内力两千以上\n");
                  write("    消耗最大内力两百点\n");
                  write("    消耗道行五十年\n");
                  break;
         case 5:  write("你的法宝"+HIB+"抵抗力"+NOR+"已经不能再升级了。\n");
      } 
      switch( force_stars )   {
         case 1:  write(HIM+"内功抵抗力" + NOR+ "(armor_vs_force)升级需要：\n");
                  write("    道行一百年以上\n");
                  write("    内力五百以上\n");
                  write("    消耗最大内力一百点\n");
                  break;
         case 2:  write(HIM+"内功抵抗力" + NOR+ "(armor_vs_force)升级需要：\n");
                  write("    道行五百年以上\n");
                  write("    内力一千以上\n");
                  write("    消耗最大内力一百五十点\n");
                  break;
         case 3:  write(HIM+"内功抵抗力" + NOR+ "(armor_vs_force)升级需要：\n");
                  write("    道行一千年以上\n");
                  write("    内力一千五以上\n");
                  write("    消耗最大内力两百五十点\n");
                  break;
         case 4:  write(HIM+"内功抵抗力" + NOR+ "(armor_vs_force)升级需要：\n");
                  write("    道行一千五百年以上\n");
                  write("    内力两千以上\n");
                  write("    消耗最大内力四百点\n");
                  break;
         case 5:  write("你的法宝"+HIM+"内功抵抗力"+NOR+"已经不能再升级了。\n");
      }
      switch( spells_stars )   {
         case 1:  write(HIC+"魔法攻击力" + NOR+ "(spells)升级需要：\n");
                  write("    道行两百年以上\n");
                  write("    法力五百以上\n");
                  write("    消耗最大法力五十点\n");
                  write("    消耗道行五年\n");
                  break;
         case 2:  write(HIC+"魔法攻击力" + NOR+ "(spells)升级需要：\n");
                  write("    道行五百年以上\n");
                  write("    法力一千以上\n");
                  write("    消耗最大法力一百点\n");
                  write("    消耗道行二十年\n");
                  break;
         case 3:  write(HIC+"魔法攻击力" + NOR+ "(spells)升级需要：\n");
                  write("    道行一千年以上\n");
                  write("    法力一千五以上\n");
                  write("    消耗最大法力一百五十点\n");
                  write("    消耗道行五十年\n");
                  break;
         case 4:  write(HIC+"魔法攻击力" + NOR+ "(spells)升级需要：\n");
                  write("    道行一千五百年以上\n");
                  write("    法力两千以上\n");
                  write("    消耗最大法力两百点\n");
                  write("    消耗道行一百年\n");
                  break;
         case 5:  write("你的法宝"+HIC+"魔法攻击力"+NOR+"已经不能再升级了。\n");
      }
      switch( vs_spells_stars )   {
         case 1:  write(HIW+"魔法抵抗力" + NOR+ "(armor_vs_spells)升级需要：\n");
                  write("    道行两百年以上\n");
                  write("    法力五百以上\n");
                  write("    消耗最大法力一百点\n");
                  break;
         case 2:  write(HIW+"魔法抵抗力" + NOR+ "(armor_vs_spells)升级需要：\n");
                  write("    道行五百年以上\n");
                  write("    法力一千以上\n");
                  write("    消耗最大法力一百五十点\n");
                  break;
         case 3:  write(HIW+"魔法抵抗力" + NOR+ "(armor_vs_spells)升级需要：\n");
                  write("    道行一千年以上\n");
                  write("    法力一千五以上\n");
                  write("    消耗最大法力三百点\n");
                  break;
         case 4:  write(HIW+"魔法抵抗力" + NOR+ "(armor_vs_spells)升级需要：\n");
                  write("    道行一千五百年以上\n");
                  write("    法力两千以上\n");
                  write("    消耗最大法力五百点\n");
                  break;
         case 5:  write("你的法宝"+HIW+"魔法抵抗力"+NOR+"已经不能再升级了。\n");
      }
   }
   
   return 1;
}

int  do_upgrade(string arg)
{
   string name, property;
   object fabao_ob, me=this_player();
   int   stars, upgraded;
  
   if( !arg || arg == "")   {
      write("请用 upgrade 法宝名 for 升级特性 来升级。\n");
      write("升级特性可用 cost 法宝名 来查看。\n");
      return 1;
   }
      
   if( sscanf(arg, "%s for %s", name, property) != 2)  {
      write("请用 upgrade 法宝名 for 升级特性 来升级。\n");
      write("升级特性可用 cost 法宝名 来查看。\n");
      return 1;
   }
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");
      
   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");
     
   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能升级。\n");
          
   if( fabao_ob->query("series_no") == "1")  {   // weapon
      if( property != "damage" )
         return notify_fail("法宝没有这个升级特性。\n");
      
      stars = fabao_ob->query("stars/"+property);
      upgraded = fabao_ob->query("upgraded/"+property) + 1;
      switch(stars)   {
         case 1:  if( me->query("combat_exp") < (20000+upgraded*16000) ||
                  me->query("max_force") < 500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("weapon_prop/damage", 10);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -10);
                  me->add("combat_exp", -200);
                  break;
         case 2:  if( me->query("combat_exp") < (100000+upgraded*80000) ||
                  me->query("max_force") < 1000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("weapon_prop/damage", 10);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -20);
                  me->add("combat_exp", -2000);
                  break;
         case 3:  if( me->query("combat_exp") < (500000+upgraded*100000) ||
                  me->query("max_force") < 1500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("weapon_prop/damage", 10);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -30);
                  me->add("combat_exp", -4000);
                  break;
         case 4:  if( me->query("combat_exp") < (1000000+upgraded*100000) ||
                  me->query("max_force") < 2000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("weapon_prop/damage", 10);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -40);
                  me->add("combat_exp", -10000);
                  break;
         case 5:  return notify_fail("你的法宝已经不能再升级了。\n");
      }
      write(fabao_ob->query("name")+"的"+HIG+"伤害力"+NOR+"增加了！\n");
   }
   else if(fabao_ob->query("series_no") == "2" ||
   fabao_ob->query("series_no") == "3")   {   // armor
      if( property != "dodge" && property != "armor" &&
      property != "armor_vs_force" && property != "spells" &&
      property != "armor_vs_spells" )
         return notify_fail("法宝没有这个升级特性。\n");
      
      stars = fabao_ob->query("stars/"+property); 
      upgraded = fabao_ob->query("upgraded/"+property) + 1; 
      if( property == "dodge" )   {
         switch(stars)  { 
            case 1:if( me->query("combat_exp") < (20000+36000*upgraded) )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/dodge", 1);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("combat_exp", -1000);
                  break;
            case 2:if( me->query("combat_exp") < (200000+60000*upgraded) )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/dodge", 1);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("combat_exp", -4000);
                  break;
            case 3:if( me->query("combat_exp") < (500000+upgraded*100000) )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/dodge", 2);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("combat_exp", -10000);
                  break;
            case 4:if( me->query("combat_exp") < (1000000+upgraded*100000) )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/dodge", 2);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("combat_exp", -20000);
                  break;
            case 5: 
                  return notify_fail("你的法宝"+HIY+"防御力"+NOR+"已经不能再升级了。\n");
         }
         write(fabao_ob->query("name")+"的"+HIY+"防御力"+NOR+"增加了！\n");
      }
      else if( property == "armor" )  {
         switch(stars)  {
            case 1: if( me->query("combat_exp") < (20000+16000*upgraded) ||
                  me->query("max_force") < 500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor", 2);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -10);
                  me->add("combat_exp", -200);
                  break;
            case 2: if( me->query("combat_exp") < (100000+upgraded*80000) ||
                  me->query("max_force") < 1000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor", 3);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -20);
                  me->add("combat_exp", -1000);
                  break;
            case 3: if( me->query("combat_exp") < (500000+upgraded*100000) ||
                  me->query("max_force") < 1500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor", 4);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -30);
                  me->add("combat_exp", -4000);
                  break;
            case 4: if( me->query("combat_exp") < (1000000+upgraded*100000) ||
                  me->query("max_force") < 2000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor", 5);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -40);
                  me->add("combat_exp", -10000);
                  break;
            case 5:  return notify_fail("你的法宝"+HIB+"抵抗力"+NOR+"已经不能再升级了。\n");
         }
         write(fabao_ob->query("name")+"的"+HIB+"抵抗力"+NOR+"增加了！\n");
      }
      else if( property == "armor_vs_force" )  {
         switch(stars)  {
            case 1: if( me->query("combat_exp") < (20000+upgraded*16000) ||
                  me->query("max_force") < 500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor_vs_force", 20);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -20);
                  break;
            case 2: if( me->query("combat_exp") < (100000+upgraded*80000) ||
                  me->query("max_force") < 1000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->set("armor_prop/armor_vs_force", 30);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -30);
                  break;
            case 3: if( me->query("combat_exp") < (500000+upgraded*100000) ||
                  me->query("max_force") < 1500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor_vs_force", 40);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -50);
                  break;
            case 4: if( me->query("combat_exp") < (1000000+upgraded*100000) ||
                  me->query("max_force") < 2000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor_vs_force", 50);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_force", -80);
                  break;
            case 5:  return notify_fail("你的法宝"+HIM+"内功抵抗力"+NOR+"已经不能再升级了。\n");
         }
         write(fabao_ob->query("name")+"的"+HIM+"内功抵抗力"+NOR+"增加了！\n");
      }
      else if( property == "spells" )  {
         switch(stars)   {
            case 1: if( me->query("combat_exp") < (20000+upgraded*36000) ||
                  me->query("max_mana") < 500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/spells", 1);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_mana", -10);
                  me->add("combat_exp", -1000);
                  break;
            case 2: if( me->query("combat_exp") < (200000+upgraded*60000) ||
                  me->query("max_mana") < 1000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/spells", 1);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_mana", -20);
                  me->add("combat_exp", -4000);
                  break;
            case 3: if( me->query("combat_exp") < (500000+upgraded*100000) ||
                  me->query("max_mana") < 1500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/spells", 2);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_mana", -30);
                  me->add("combat_exp", -10000);
                  break;
            case 4: if( me->query("combat_exp") < (1000000+upgraded*100000) ||
                  me->query("max_mana") < 2000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/spells", 2);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_mana", -40);
                  me->add("combat_exp", -20000);
                  break;
            case 5:  return notify_fail("你的法宝"+HIC+"魔法攻击力"+NOR+"已经不能再升级了。\n");
         }
         write(fabao_ob->query("name")+"的"+HIC+"魔法攻击力"+NOR+"增加了！\n");
      }
      else if( property == "armor_vs_spells" )  {
         switch(stars)  {
            case 1: if( me->query("combat_exp") < (20000+upgraded*36000) || 
                  me->query("max_mana") < 500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor_vs_spells", 20);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_mana", -20);
                  break;
            case 2: if( me->query("combat_exp") < (20000+upgraded*80000) || 
                  me->query("max_mana") < 1000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor_vs_spells", 30);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_mana", -30);
                  break;
            case 3: if( me->query("combat_exp") < (500000+upgraded*100000) || 
                  me->query("max_mana") < 1500 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor_vs_spells", 40);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_mana", -60);
                  break;
            case 4: if( me->query("combat_exp") < (1000000+upgraded*100000) || 
                  me->query("max_mana") < 2000 )
                     return notify_fail("不够升级条件，请用 cost 查询。\n");
                  fabao_ob->add("armor_prop/armor_vs_spells", 50);
                  fabao_ob->add("upgraded/"+property, 1);
                  if( upgraded == 5 )  {
                     fabao_ob->add("stars/"+property, 1);
                     fabao_ob->set("upgraded/"+property, 0);
                  }
                  me->add("max_mana", -100);
                  break;
            case 5:  return notify_fail("你的法宝"+HIW+"魔法抵抗力"+NOR+"已经不能再升级了。\n");
         }
         write(fabao_ob->query("name")+"的"+HIW+"魔法抵抗力"+NOR+"增加了！\n");
      } 
   }
  
   me->save(); 
   fabao_ob->save();
   
   return 1;
}

int  do_change_name(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_name 法宝 新中文名 来改名。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_name 法宝 新中文名 来改名。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");
   
   newname += "$NOR$";      
   arg = newname;
            
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
        
   if( !check_legal_name(arg, 12) )   {
      return 1; 
   }
  
   arg = newname;
    
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
  
   fabao_ob->set("name", arg);
   fabao_ob->save();     
   
   write("改动成功。\n");
   return 1;
}
      
int  do_change_id(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
   string *id_list, *t_list;
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_id 法宝 新英文名 来改名。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_id 法宝 新英文名 来改名。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");

   if( !check_legal_id( newname ) )     return 1;
  
   newname = replace_string(newname, " ", "_"); 
   fabao_ob->set("id", newname);

   id_list = ({ newname });
   t_list = explode( newname, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   fabao_ob->set_name( fabao_ob->query("name"), id_list ); 
   fabao_ob->save();
   
   write("改动成功。\n");
   return 1;
}

      
int  do_change_desc(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_desc 法宝 新描述 来重新描述法宝。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_desc 法宝 新描述 来重新描述法宝。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");

   if( !check_legal_name(newname, 60 ) )     return 1;
   
   fabao_ob->set("long", newname);
   fabao_ob->save();
   
   write("改动成功。\n");
   return 1;
}
      
int  do_change_unit(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_unit 法宝 单位 来指定法宝单位。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_unit 法宝 单位 来指定法宝单位。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");

   if( !check_legal_name(newname, 2 ) )     return 1;
   
   fabao_ob->set("unit", newname);
   fabao_ob->save();
   
   write("改动成功。\n");
   return 1;
}



