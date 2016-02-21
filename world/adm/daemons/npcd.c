// named.c

//#pragma optimize
//#pragma save_binary

#include <npc/name.h>
#include <npc/chinese.c>
#include <npc/japanese.c>
#include <npc/european.c>
#include <npc/masia.c>

#define WUDANG_ZHANG             "/d/33tian/npc/laojun"
#define HUASHAN_FENG             "/d/qujing/lingshan/npc/rulai"
#define GAIBANG_HONG             "/d/xueshan/npc/kongque"
#define BTSHAN_OUYANG            "/d/lingtai/npc/swk"
object *all_interactive();
object get_object(string name);
mapping levels = ([
//      combat_exp   skill_level
        100000     : 80,                // level 1
        150000     : 90,                // level 1.5
        200000     : 100,               // level 2
        300000     : 115,                // level 2.5
        400000     : 125,               // level 3
        500000     : 135,                // level 3.5
        800000     : 150,               // level 4
        1200000    : 175,               // level 5
        1600000    : 200,               // level 6
        2000000    : 225,               // level 7
        2500000    : 250,               // level 8
        2700000    : 275,               // level 9
        3000000    : 300,               // level 10

]);

// return the character(ob) 's level, 0 is lowest
int check_level(object ob)
{
        int *exp;
        int i;

        exp = sort_array(keys(levels), 1);
        for (i = 0; i < sizeof(exp); i++)
                if (ob->query("combat_exp") < exp[i]) break;
        return i;
}

// set the the level of the npc's skill
void init_npc_skill(object ob, int lvl)
{
        int sk_lvl;
        string *ks;
        int i;
        int exp;

        if (lvl < 1 || lvl > sizeof(levels))
                return;
        exp = sort_array(keys(levels), 1)[lvl - 1];
        ob->set("combat_exp",exp);
        sk_lvl = levels[exp];
        if (! ob->query_skills())
                return;
        ks = keys(ob->query_skills());
        for (i = 0; i < sizeof(ks); i++)
                ob->set_skill(ks[i], sk_lvl);
                
}

string *nations = ({ "中国", "雅典圣城", "龟慈", "荷兰", "天竺", "蒙古",
                     "俄罗斯", "英吉利", "法兰西", "西班牙", "葡萄牙",
                     "比利时", "塔吉克斯坦", "哈沙克斯坦", "乌兹别克斯坦" });

// generate a npc with nation & skill level
object create_npc(string nation, int lvl)
{
        object ob;

        switch (nation)
        {
        case "中国":
                ob = new(CLASS_D("generate") + "/chinese");
                NPC_D->generate_cn_name(ob);
                break;
        case "雅典圣城":
                ob = new(CLASS_D("generate") + "/japanese");
                NPC_D->generate_jp_name(ob);
                break;
        case "花剌子模":
        case "龟慈":
        case "英吉利":
        case "法兰西":
        case "西班牙":
        case "葡萄牙":
        case "比利时":
        case "荷兰":
        case "天竺":
        case "俄罗斯":
        case "塔吉克斯坦":
        case "哈沙克斯坦":
        case "乌兹别克斯坦":
        case "蒙古":
                return 0;
        }

        ob->set("nation", nation);
        init_npc_skill(ob, lvl);

        return ob;
}

// generate challenger
object create_challenger()
{
        string *n;
        object *ob;
        int max_level;
        int i;

        ob = all_interactive();
        max_level = 0;
        for (i = 0; i < sizeof(ob); i++)
                if (max_level < check_level(ob[i]))
                        max_level = check_level(ob[i]);

        max_level++;

        // 没有中国挑战者
        n = nations - ({ "中国" });

        // temp: only japanese challenger
        n = ({ "雅典圣城" });
        return create_npc(n[random(sizeof(n))], 1 + random(max_level));
}

// set the basic parameter from me
void set_from_me(object tob, object fob)
{
        mapping my, hp_status;
        int scale;

        hp_status = fob->query_entire_dbase();
        my = tob->query_entire_dbase();

        if (undefinedp(my["scale"]))
                my["scale"] = 100;
        scale = my["scale"];

        my["str"] = hp_status["str"] * scale / 100;
        my["int"] = hp_status["int"] * scale / 100;
        my["con"] = hp_status["con"] * scale / 100;
        my["dex"] = hp_status["spi"] * scale / 100;

        my["max_kee"]     = hp_status["max_kee"]   * scale / 100;
        my["eff_kee"]     = my["max_kee"];
        my["kee"]         = my["max_kee"];
        my["max_sen"]   = hp_status["max_sen"] * scale / 100;
        my["eff_sen"]   = my["max_sen"];
        my["sen"]       = my["max_sen"];
        my["max_force"]  = hp_status["max_force"]* scale / 100;
        my["force"]      = my["max_force"];
        my["force_factor"]      = hp_status["max_force"] / 25;
        my["max_mana"]  = hp_status["max_mana"]* scale / 100;
        my["mana"]      = my["max_mana"];
        my["mana_factor"]      = hp_status["max_mana"] / 25;
}

// get all ultra master
object *query_ultra_master()
{
        return ({ get_object(WUDANG_ZHANG),
                  get_object(HUASHAN_FENG),
                  get_object(GAIBANG_HONG),
                  get_object(BTSHAN_OUYANG) });
}
object *all_interactive()
{
        return efun::users();
}
object get_object(string name)
{
        object ob;
        if (ob = find_object(name))
                return ob;
        return load_object(name);
}

