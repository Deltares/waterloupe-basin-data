from datetime import datetime

class ChannelInfo():

    @property
    def channelinfo_id(self) -> str:
        return self.name + ' (' + self.unit + ')'

    @property
    def location(self) -> int:
        return self.__location

    @location.setter
    def location(self, value:int):
        self.__location = value

    @property
    def length(self) -> int:
        return self.__length

    @length.setter
    def length(self, value:int):
        self.__length = value
    
    @property
    def name(self) -> int:
        return self.__name

    @name.setter
    def name(self, value:int):
        self.__name = value

    @property
    def unit(self) -> int:
        return self.__unit

    @unit.setter
    def unit(self, value:int):
        self.__unit = value
    
    @property
    def date(self) -> str:
        return self.__date

    @date.setter
    def date(self, value:str):
        self.__date = value

    @property
    def time(self) -> str:
        return self.__time

    @time.setter
    def time(self, value:str):
        self.__time = value

    @property
    def comment(self) -> str:
        return self.__comment

    @comment.setter
    def comment(self, value:str):
        self.__comment = value

    @property
    def format(self) -> int:
        return self.__format

    @format.setter
    def format(self, value:int):
        self.__format = value

    @property
    def data_width(self) -> int:
        return self.__data_width

    @data_width.setter
    def data_width(self, value:int):
        self.__data_width = value
    
    @property
    def date_time_now(self) -> datetime:
        return self.__date_time_now

    @date_time_now.setter
    def date_time_now(self, value:datetime):
        self.__date_time_now= value

    # start VB_DB_CHANHEADER

    @property
    def t0(self) -> float:
        return self.__t0
    @t0.setter
    def t0(self, value:float):
        self.__t0= value

    @property
    def dt(self) -> float:
        return self.__dt
    @dt.setter
    def dt(self, value:float):
        self.__dt= value

    @property
    def sensortype(self) -> int:
        return self.__sensortype
    @sensortype.setter
    def sensortype(self, value:int):
        self.__sensortype= value

    @property
    def supplyvoltage(self) -> int:
        return self.__supplyvoltage
    @supplyvoltage.setter
    def supplyvoltage(self, value:int):
        self.__supplyvoltage= value

    @property
    def filtchar(self) -> int:
        return self.__filtchar
    @filtchar.setter
    def filtchar(self, value:int):
        self.__filtchar= value

    @property
    def filtfreq(self) -> int:
        return self.__filtfreq
    @filtfreq.setter
    def filtfreq(self, value:int):
        self.__filtfreq= value

    @property
    def tareval(self) -> float:
        return self.__tareval
    @tareval.setter
    def tareval(self, value:float):
        self.__tareval= value

    @property
    def zeroval(self) -> float:
        return self.__zeroval
    @zeroval.setter
    def zeroval(self, value:float):
        self.__zeroval= value

    @property
    def measrange(self) -> float:
        return self.__measrange
    @measrange.setter
    def measrange(self, value:float):
        self.__measrange= value

    @property
    def inchar(self) -> float:
        return self.__inchar
    @inchar.setter
    def inchar(self, value:float):
        self.__inchar= value

    @property
    def serno(self) -> str:
        return self.__serno
    @serno.setter
    def serno(self, value:str):
        self.__serno= value

    @property
    def physunit(self) -> str:
        return self.__physunit
    @physunit.setter
    def physunit(self, value:str):
        self.__physunit= value

    @property
    def nativeunit(self) -> str:
        return self.__nativeunit
    @nativeunit.setter
    def nativeunit(self, value:str):
        self.__nativeunit= value

    @property
    def slot(self) -> int:
        return self.__slot
    @slot.setter
    def slot(self, value:int):
        self.__slot= value

    @property
    def subslot(self) -> int:
        return self.__subslot
    @subslot.setter
    def subslot(self, value:int):
        self.__subslot= value

    @property
    def amptype(self) -> int:
        return self.__amptype
    @amptype.setter
    def amptype(self, value:int):
        self.__amptype= value

    @property
    def aptype(self) -> int:
        return self.__aptype
    @aptype.setter
    def aptype(self, value:int):
        self.__aptype= value

    @property
    def kfactor(self) -> float:
        return self.__kfactor
    @kfactor.setter
    def kfactor(self, value:float):
        self.__kfactor= value

    @property
    def bfactor(self) -> float:
        return self.__bfactor
    @bfactor.setter
    def bfactor(self, value:float):
        self.__bfactor= value

    @property
    def meassig(self) -> int:
        return self.__meassig
    @meassig.setter
    def meassig(self, value:int):
        self.__meassig= value

    @property
    def ampinput(self) -> int:
        return self.__ampinput
    @ampinput.setter
    def ampinput(self, value:int):
        self.__ampinput= value

    @property
    def hpfilt(self) -> int:
        return self.__hpfilt
    @hpfilt.setter
    def hpfilt(self, value:int):
        self.__hpfilt= value

    @property
    def olimportinfo(self) -> str:
        return self.__olimportinfo
    @olimportinfo.setter
    def olimportinfo(self, value:str):
        self.__olimportinfo= value

    @property
    def scaletype(self) -> str:
        return self.__scaletype
    @scaletype.setter
    def scaletype(self, value:str):
        self.__scaletype= value

    @property
    def softwaretareval(self) -> float:
        return self.__softwaretareval
    @softwaretareval.setter
    def softwaretareval(self, value:float):
        self.__softwaretareval= value

    @property
    def writeprotected(self) -> bool:
        return self.__writeprotected
    @writeprotected.setter
    def writeprotected(self, value:bool):
        self.__writeprotected= value

    @property
    def nominalrange(self) -> float:
        return self.__nominalrange
    @nominalrange.setter
    def nominalrange(self, value:float):
        self.__nominalrange= value

    @property
    def reserve(self) -> str:
        return self.__reserve
    @reserve.setter
    def reserve(self, value:str):
        self.__reserve= value


    # end VB_DB_CHANHEADER

    @property
    def lin_mode(self) -> int:
        return self.__lin_mode

    @lin_mode.setter
    def lin_mode(self, value:int):
        self.__lin_mode= value

    @property
    def user_scale_type(self) -> int:
        return self.__user_scale_type

    @user_scale_type.setter
    def user_scale_type(self, value:int):
        self.__user_scale_type= value

    @property
    def number_of_scalar_data(self) -> int:
        return self.__number_of_scalar_data

    @number_of_scalar_data.setter
    def number_of_scalar_data(self, value:int):
        self.__number_of_scalar_data= value

    @property
    def thermo_type(self) -> int:
        return self.__thermo_type

    @thermo_type.setter
    def thermo_type(self, value:int):
        self.__thermo_type = value

    @property
    def formula(self) -> str:
        return self.__formula

    @formula.setter
    def formula(self, value:str):
        self.__formula = value

    @property
    def db_sensor_info(self) -> str:
        return self.__db_sensor_info

    @db_sensor_info.setter
    def db_sensor_info(self, value:str):
        self.__db_sensor_info = value
    
    @property
    def data_pos(self) -> int:
        return self.__data_pos

    @data_pos.setter
    def data_pos(self, value:int):
        self.__data_pos = value
    
    @property
    def data_size(self) -> int:
        return self.length * self.data_width
