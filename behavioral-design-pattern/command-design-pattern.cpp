#include <bits/stdc++.h>
using namespace std;
//Command Design Pattern: The Command Design Pattern is a behavioral design pattern that turns a request into a stand-alone object that contains all the information about the request. This transformation allows the decoupling of objects that produce commands from objects that execute them. This pattern is often used to implement features such as undo/redo, logging, and queuing of requests.


//Receiver class
//This class represents the receiver of the command. In this case, it is an
//Air Conditioner that has methods to turn it on and off and set the temperature.
class AirConditioner{
    private:
    bool isOn;
    int temperature;
    
    public:
    AirConditioner(): isOn(false), temperature(24){}
    /**
     * @brief Turns the air conditioner on.
     * 
     * This method sets the isOn flag to true and prints a message indicating
     * that the air conditioner has been turned on.
     */
    void turnACOn(){
        isOn=true;
        cout<<"AC is turned On"<<endl;
    }
    
    /**
     * @brief Turns the air conditioner off.
     * 
     * This method sets the isOn flag to false and prints a message indicating
     * that the air conditioner has been turned off.
     */
    void turnACOff(){
        isOn=false;
        cout<<"AC is turned False"<<endl;
    }

    /**
     * @brief Sets the temperature of the air conditioner.
     * 
     * This method takes an integer parameter and sets the temperature of the
     * air conditioner to the given value. The current temperature is printed
     * to the console.
     * @param t The temperature to be set.
     */
    void setTemperature(int t){
        temperature = t;
        cout<<"Temperature is set to "<<t<<endl;
    }
    /**
     * @brief Gets the current temperature of the air conditioner.
     * 
     * This method returns the current temperature of the air conditioner.
     * @return The current temperature of the air conditioner.
     */
    int getTemperature(){
        return temperature;
    }
    
};


//commands
//Abstract class for commands
//This class provides a common interface for different commands that can be
//executed on an AirConditioner object. The interface includes two methods:
//execute() and undo(). The execute() method will execute the command and
//the undo() method can be used to cancel the effects of the command.
class ICommand {
    private:
    AirConditioner *airConditioner;
    
    public:
    virtual void execute()=0;
    virtual void undo()=0;
};


/**
 * @brief Abstract class for commands
 *
 * This class provides a common interface for different commands that can be
 * executed on an AirConditioner object. The interface includes two methods:
 * execute() and undo(). The execute() method will execute the command and
 * the undo() method will undo the last command that was executed.
 */
class TurnACOnCommand: public ICommand {
    private:
    AirConditioner *airConditioner;
    
    public:
    TurnACOnCommand(AirConditioner *ac): airConditioner(ac){};
    /**
     * @brief Executes the command.
     * 
     * This method turns on the air conditioner.
     */
    void execute(){
        airConditioner->turnACOn();
    }

    /**
     * @brief Undoes the command.
     * 
     * This method turns off the air conditioner, reversing the 
     * effect of the execute() method.
     */
    void undo(){
        airConditioner->turnACOff();
    }
};

class TurnACOffCommand: public ICommand {
    private:
    AirConditioner *airConditioner;
    
    public:
    
    /**
     * @brief Executes the command.
     * 
     * This method turns off the air conditioner.
     */
    TurnACOffCommand(AirConditioner *ac): airConditioner(ac){};
    /**
     * @brief Executes the command.
     * 
     * This method turns off the air conditioner.
     */
    void execute(){
        airConditioner->turnACOff();
    }

    /**
     * @brief Reverts the command.
     * 
     * This method turns the air conditioner back on, undoing the previous command
     * that turned it off.
     */

    void undo(){
        airConditioner->turnACOn();
    }
};

/**
 * @brief A command to set the temperature of the air conditioner.
 *
 * This class encapsulates the logic of setting the temperature of the air
 * conditioner. It takes in an AirConditioner object and an integer temperature
 * in the constructor. In the execute() method, it sets the temperature of the
 * air conditioner to the given next_temperature. In the undo() method, it sets
 * the temperature of the air conditioner back to the previous_temperature.
 */
class SetTemperatureCommand: public ICommand {
    private:
    AirConditioner *airConditioner;
    int previous_temperature;
    int next_temperature;
    
    public:
    /**
     * @brief Constructor for SetTemperatureCommand.
     * 
     * This constructor takes in an AirConditioner object and an integer
     * temperature. It sets the airConditioner field to the given AirConditioner
     * object and next_temperature field to the given temperature. It also
     * records the previous temperature by calling getTemperature() on the
     * AirConditioner object.
     * @param ac The AirConditioner object to be controlled.
     * @param temperature The temperature to be set.
     */
    SetTemperatureCommand(AirConditioner *ac, int temperature): airConditioner(ac), next_temperature(temperature){
        previous_temperature = airConditioner->getTemperature();
    }
    void execute(){
        airConditioner->setTemperature(next_temperature);
    /**
     * Sets the temperature of the air conditioner to the next_temperature.
     * This method is an implementation of the execute method of the
     * ICommand interface.
     */
    }
/**
 * Reverts the air conditioner's temperature to the previously 
 * recorded temperature. This method is an implementation of 
 * the undo method of the ICommand interface, allowing the 
 * command to reverse its effect.
 */
    void undo(){
        airConditioner->setTemperature(previous_temperature);
    }
};

//Invoker

/**
 * Remote class is an invoker in the command design pattern.
 * It uses a stack to store commands and uses the command
 * interface to execute and undo commands.
 * The invoker is responsible for managing the command
 * stack and executing the commands in the stack.
 */
class Remote{
    private:
    stack<ICommand*>commands;
    
    public:
    /**
     * Remote constructor.
     * Removes all commands from the stack.
     */
    Remote(){
        while(!commands.empty()){
            commands.pop();
        }
    }
    /**
     * Adds a command to the top of the stack.
     * @param cmd The command to be added to the stack.
     */
    void setCommand(ICommand *cmd){
        commands.push(cmd);
    }
    
    /**
     * Calls the execute() method of the command at the top of the stack.
     * Does nothing if the stack is empty.
     */
    void pressButton(){
        if(!commands.empty()){
            ICommand *curr_command = commands.top();
            curr_command->execute();
        }
    }
    
    /**
     * Pops the last command from the stack and calls its undo() method.
     * This can be used to revert the state of the AirConditioner to its state
     * before the last command was executed.
     */
    void undoButton(){
        if(!commands.empty()){
            ICommand *curr_command = commands.top();
            curr_command->undo();
            commands.pop();
        }
    }
};


/**
 * @brief Main function to demonstrate the command design pattern.
 * 
 * This function creates an AirConditioner object and a Remote object.
 * It then sets the command on the remote to a TurnACOnCommand and presses the button.
 * After that, it sets the command on the remote to a SetTemperatureCommand for 30 degrees and presses the button.
 * Finally, it undoes the previous two commands by pressing the undo button twice.
 */
int main(){
    AirConditioner *airConditioner = new AirConditioner();
    Remote *remote = new Remote();
    
    remote->setCommand(new TurnACOnCommand(airConditioner));
    remote->pressButton();
    remote->setCommand(new SetTemperatureCommand(airConditioner, 30));
    remote->pressButton();
    remote->undoButton();
    remote->undoButton();
}
