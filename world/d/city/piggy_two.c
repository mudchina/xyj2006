// mon 9/2/98
// pig game for partners. re-define the scoring method after a round.

inherit __DIR__"piggy.c";

// the limit to get a pig head.
#define LIMIT  2000
// the penalty for getting pig head.
#define PIG_PENALTY 3

// define who is who's partner.
mapping partner=([
	"east": "west",
	"west": "east",
	"south": "north",
	"north": "south",
	]);
int *part_index=({2,3,0,1});

void finish_round()
{
    int i=NUM, j=CARDNO, score, k;
    string dir=find_large();
    object me;
    object *result_ob=allocate(NUM); // mon 6/13/98
    int *result_sc=allocate(NUM); // mon 6/13/98
    int no_head=0;

    while(remove_call_out("check_wait")!=-1);

    reset_eval_cost();

    if (GAMEINFO["round"] == 13)
    {
	TABLE["cond"] = "算分";
	while(j--)
	{
	    if (CARDS[j+1]["status"] != "played")
		tell_room(HERE,"函数错误：finish_round。"+CARDS[j+1]["name"]+"还没打过。\n");
	    continue;
	}
	
	// mon: check pig_owner
	if(member_array(PIG_OWNER, DIR)!=-1) score_player(PIG_OWNER);

	if (!is_dir(FULL)) { // pig_owner didn't collect all.
	  i=NUM;
 	  while(i--) {
	      result_sc[i]=0;
	  }
	  i=NUM;
 	  while(i--) {
	    score=score_player(DIR[i]);
	    // use total score of the two to calculate points.
	    result_sc[i]+=score; 
	    result_sc[part_index[i]]+=score;
	  }
	  i=NUM;
	  while(i--) {
	    score=result_sc[i]/2; // each one show half of the score.
	    me=find_me(DIR[i]);
	    me->add("piggy/score", score);
	    me->add("piggy/hand_played", 1);
	    result_ob[i]=me; // mon
	    SCORING["hand"][DIR[i]]+=score;
	    if ((SCORING["sitting"][DIR[i]]+=score) <= -LIMIT) {
		PIGHEAD+=({DIR[i]});
	    }
	  }
	} else {// pig_owner collected all.
	    i=NUM;
	    score=score_player(FULL)/2;
	    while(i--)
	    {
		(me=find_me(DIR[i]))->add("piggy/hand_played", 1);
		if((FULL != DIR[i]) && (FULL !=partner[DIR[i]])) {
		    PIGHEAD+=({DIR[i]});
		} else {
		  me->add("piggy/score", score);
		  SCORING["hand"][DIR[i]]+=score;
		  SCORING["sitting"][DIR[i]]+=score;
		}
	    }
	}
	
	// mon
	k=sizeof(PIGHEAD);
	if(k==0) // if no pighead comes out.
	    update_ranking(result_ob, result_sc);
	else {  // if pig heads comes out.
	    if(k<NUM) no_head=k*PIG_PENALTY/(NUM-k);
	    for(j=0; j<NUM; j++) {
	      if(member_array(DIR[j], PIGHEAD)==-1) 
		  update_one_rank(find_me(DIR[j]), no_head);
	      else
		  update_one_rank(find_me(DIR[j]), -PIG_PENALTY);
	    }
	}

	while(k--)
		find_me(PIGHEAD[k])->add("piggy/head_received", 1);
	tell_room(HERE, display_score());
	if (sizeof(PIGHEAD))
	{
	    all_have("given_head");
	    renew("sitting");
	}
	else renew("hand");
	return;
    }
    GAMEINFO[GAMEINFO["suit"]]++;
    GAMEINFO["rlead"]=dir;
    GAMEINFO["next"]=dir;
    find_me(dir);
    tell_room(HERE, display_table(dir));
    renew("round");
    return;
}
