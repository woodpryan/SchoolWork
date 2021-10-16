class Widget:
    def __init__(self):
        self.wheels = list()
        self.container = None
        self.body = None
    def makeWidget(self, widgetType):
        if(widgetType == 'Big'):
            builder = BigWidgetBuilder()
        elif(widgetType == 'Small'):
            build = SmallWidgetBuilder()

        builder.buildWheels()
        builder.buildContainer()
        builder.buildBody()
        self = builder.widget

    def attachWheel(self,wheel):
        self.wheels.append(wheel)
    def setContainerVolume(self,volume):
        self.container = volume
    def setBody(self,bodytype):
        self.body = bodytype
    
class Builder:
    def getWheel(self, size):
        aWheel = Wheel()
        aWheel.size = size
        return aWheel;

    def getContainer(self, v):
        aContainer = Container()
        aContainer.volume = v
        return aContainer;

    def getBody(self, bShape):
        aBody = Body()
        aBody.shape = bShape
        return aBody;

class BigWidgetBuilder:
    def _init_(self):
        self.widget  = Widget()
        self.builder = Builder()

    def buildWheels(self):
        self.widget.attachWheel(self.builder.getWheel(20))
        self.widget.attachWheel(self.builder.getWheel(20))
        self.widget.attachWheel(self.builder.getWheel(20))
        self.widget.attachWheel(self.builder.getWheel(20))
        
    def buildContainer(self): 
        self.widget.setContainerVolume(self.builder.getContainer(50))
    def buildBody(self):
        self.widget.setBody(self.builder.getBody("Bucket"))

class SmallWidgetBuilder:
    def _init_(self):
        self.widget = Widget()
        self.builder = Builder()

    def buildWheels(self):
        self.widget.attachWheel(self.builder.getWheel(5))
        self.widget.attachWheel(self.builder.getWheel(5))
        self.widget.attachWheel(self.builder.getWheel(5))
        self.widget.attachWheel(self.builder.getWheel(5))
        
    def buildContainer(self): 
        self.widget.setContainerVolume(self.builder.getContainer(10))
    def buildBody(self):
        self.widther.setBody(self.builder.getBody("Glass"))
        
class Wheel:
    size = None
class Container:
    volume = None
class Body:
    shape = None

def main():
    widget = Widget()
    widget.makeWidget("Big")
    
main()
