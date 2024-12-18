
// The Chain of Responsibility is a behavioral design pattern that allows an object to pass a request along a chain of potential handlers until one of them handles it. This pattern decouples the sender of a request from its receiver, allowing multiple objects to handle the request without the sender needing to know which object will handle it.
#include <bits/stdc++.h>
using namespace std;

/**
 * The LogProcessor class is the base class for all log processors in the chain.
 * It provides a common interface for handling log messages and passing them to
 * the next processor in the chain.
 */
class LogProcessor{
    protected:
    LogProcessor *nextLogProcessor;
    
    public:
    const int INFO = 1;
    const int DEBUG = 2;
    const int ERROR = 3;
    
/**
 * Constructor for LogProcessor.
 * 
 * @param nlp A pointer to the next LogProcessor in the chain. This allows 
 *            the current processor to pass the request to the next processor 
 *            if it cannot handle it. If this is the last processor in the chain, 
 *            nlp should be NULL.
 */

    LogProcessor(LogProcessor *nlp){
        nextLogProcessor = nlp;
    }
/**
 * Pass a log message to the next processor in the chain, if any.
 *
 * If the current processor cannot handle the log message (i.e., if the log
 * level is greater than the level handled by the processor), the request is
 * passed to the next processor in the chain. If the current processor is the
 * last one in the chain, the message is dropped.
 *
 * @param logLevel The level of the log message. This is used to determine
 *                 whether the current processor can handle the message.
 * @param message The log message itself.
 */
    virtual void log(const int logLevel, string message){
        if(nextLogProcessor!=NULL){
            cout<<"going next"<<endl;
            nextLogProcessor->log(logLevel, message);
        }
    }
};

class InfoLogProcessor: public LogProcessor{
    public:
    InfoLogProcessor(LogProcessor *nlp): LogProcessor(nlp){}
/**
 * Handle a log message if its level is INFO.
 *
 * If the level of the message is INFO, the message is printed to the console.
 * Otherwise, the message is passed to the next processor in the chain.
 *
 * @param logLevel The level of the message. If this is INFO, the message is
 *                 handled; otherwise, it is passed to the next processor.
 * @param message The message itself.
 */
    void log(const int logLevel, string message){
        if(logLevel == INFO){
            cout<<"INFO "<<message<<endl;
        }
        else{
            LogProcessor::log(logLevel, message);
        }
    }
};

/**
 * The DebugLogProcessor class handles log messages with DEBUG level.
 * It extends the LogProcessor class.
 */
class DebugLogProcessor: public LogProcessor{
    public:
    /**
     * Constructor for DebugLogProcessor.
     * @param nlp - Pointer to the next LogProcessor
     */
    DebugLogProcessor(LogProcessor *nlp): LogProcessor(nlp){}
/**
 * Handle a log message if its level is DEBUG.
 *
 * If the level of the message is DEBUG, the message is printed to the console.
 * Otherwise, the message is passed to the next processor in the chain.
 *
 * @param logLevel The level of the message. If this is DEBUG, the message is
 *                 handled; otherwise, it is passed to the next processor.
 * @param message The message itself.
 */
    void log(const int logLevel, string message){
        if(logLevel == DEBUG){
            cout<<"DEBUG "<<message<<endl;
        }
        else{
            LogProcessor::log(logLevel, message);
        }
    }
};

/**
 * The ErrorLogProcessor class handles log messages with ERROR level.
 * It extends the LogProcessor class.
 */
class ErrorLogProcessor: public LogProcessor{
    public:
    /**
     * Constructor for ErrorLogProcessor.
     * @param nlp - Pointer to the next LogProcessor
     */
    ErrorLogProcessor(LogProcessor *nlp): LogProcessor(nlp){}
/**
 * Handle a log message if its level is ERROR.
 *
 * If the level of the message is ERROR, the message is printed to the console.
 * Otherwise, the message is passed to the next processor in the chain.
 *
 * @param logLevel The level of the message. If this is ERROR, the message is
 *                 handled; otherwise, it is passed to the next processor.
 * @param message The message itself.
 */
    void log(const int logLevel, string message){
        if(logLevel == ERROR){
            cout<<"ERROR "<<message<<endl;
        }
        else{
            LogProcessor::log(logLevel, message);
        }
    }
};

/**
 * Demonstrate the Chain of Responsibility design pattern by creating a logging
 * processor chain. The chain consists of three log processors: an InfoLogProcessor,
 * a DebugLogProcessor, and an ErrorLogProcessor. Each log processor is responsible
 * for handling a specific log level. The main function creates the log processor
 * chain and logs a message with the ERROR level. The log processor chain ensures
 * that the message is handled by the appropriate log processor.
 */
int main() {
    
    LogProcessor *logProcessor = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(NULL)));
    logProcessor->log(logProcessor->ERROR, "get error");
}