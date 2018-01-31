/**
* Contains: general commands
*/
#ifndef COM_GEN_H
#include "mud.h"
#include "conf.h"
#include "command.h"

/**
* Initializes general commands, available to all players.
*/
void InitializeGenCommands();

/**
* Logs the player out of the game.
*/
class CMDQuit:public Command
{
public:
    CMDQuit();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Saves the player.
*/
class CMDSave:public Command
{
public:
    CMDSave();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Creates a backup of the player.
*/
class CMDBackup:public Command
{
public:
    CMDBackup();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Show a list of who is logged into the mud.
*/
class CMDWho:public Command
{
public:
    CMDWho();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Toggles an option on or off.
*/
class CMDToggle:public Command
{
public:
    CMDToggle();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Display statistics specific to the player.
* @note use command pre and postprocessing to add to this.
*/
class CMDScore:public Command
{
public:
    CMDScore();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* This is the stub command for channels.
*/
class CMDChan:public Command
{
public:
    CMDChan();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Display a list of commands
* @todo clean up the listing not to use so many stringstreams.
*/
class CMDCommands:public Command
{
public:
    CMDCommands();
    /**
    * collects and organizes the command information.
    *
    * @param [in] the player object to print the information to.
    *@param [in] the type of command.
    */
    void PrintCommandInfo(Player* mobile, CommandType filter);
    /**
    * Returns a list of commands filtered by type.
    *
    * @param [in] mobile the player requesting the list.
    * @param [out] names a destination to store the new commands.
    * @param [in] filter the filter to apply.
    */
    void GetCommands(Player*mobile, std::vector<std::string>& names, CommandType filter);
    void Syntax(Player* mobile, int subcmd) const;
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Channel history for a specified channel.
* @todo consider moving chan and hist to channel.cpp(?)
*/
class CMDHist:public Command
{
public:
    CMDHist();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Displays current uptime statistics.
*/
class CMDUptime:public Command
{
public:
    CMDUptime();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Retrieves information on the specified user.
* @todo cleanup logic.
*/
class CMDWhois:public Command
{
public:
    CMDWhois();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Look at a specified object or current environment.
*/
class CMDLook:public Command
{
public:
    CMDLook();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Delete current player.
*/
class CMDSuicide:public Command
{
public:
    CMDSuicide();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
    /**
    * Used as the input handler to confirm input.
    *
    * @param [in] sock The socket to read and write from.
    * @param [in] choice the result of the yes/no input.
    * @todo remove backup?
    */
    void Confirm(Socket* sock, bool choice);
};

/**
* Broadcasts a message to the current environment.
*/
class CMDSay:public Command
{
public:
    CMDSay();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Broadcasts an emote to the current environment.
*/
class CMDEmote:public Command
{
public:
    CMDEmote();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Sets the prompt for the player.
* @todo perhaps some input verification.
*/
class CMDPrompt:public Command
{
public:
    CMDPrompt();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args,int subcmd);
};

/**
* Displays current connection statistics.
* @todo cverify logic.
*/
class CMDSockstats:public Command
{
public:
    CMDSockstats();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args, int subcmd);
};

/**
* Display a list of exits in the current environment.
*/
class CMDExits:public Command
{
public:
    CMDExits();
    bool Execute(const std::string &verb, Player* mobile,std::vector<std::string> &args, int subcmd);
};
#endif
