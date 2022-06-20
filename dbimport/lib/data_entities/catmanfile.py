class CatmanFileInfo():
    
    @property
    def version(self) -> int:
        return self.__version

    @version.setter
    def version(self, value:int):
        self.__version = value

    @property
    def data_offset(self) -> int:
        return self.__data_offset

    @data_offset.setter
    def data_offset(self, value:int):
        self.__data_offset = value

    @property
    def comment(self) -> str:
        return self.__comment

    @comment.setter
    def comment(self, value:str):
        self.__comment = value

    @property
    def number_of_channels(self) -> int:
        return self.__number_of_channels

    @number_of_channels.setter
    def number_of_channels(self, value:int):
        self.__number_of_channels = value
    
    @property
    def max_channel_length(self) -> int:
        return self.__max_channel_length

    @max_channel_length.setter
    def max_channel_length(self, value:int):
        self.__max_channel_length = value
    
    @property
    def channel_offset(self) -> list([int]):
        return self.__channel_offset

    @channel_offset.setter
    def channel_offset(self, value: list([int])):
        self.__channel_offset = value

    @property
    def reduction_factor(self) -> int:
        return self.__reduction_factor

    @reduction_factor.setter
    def reduction_factor(self, value:int):
        self.__reduction_factor = value