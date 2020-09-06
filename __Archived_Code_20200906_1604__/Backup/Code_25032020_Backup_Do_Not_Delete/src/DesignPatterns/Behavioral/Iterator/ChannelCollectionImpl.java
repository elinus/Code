package DesignPatterns.Behavioral.Iterator;

import java.util.ArrayList;
import java.util.List;

public class ChannelCollectionImpl implements ChannelCollection {

    private List<Channel> channelList;

    public ChannelCollectionImpl() {
        channelList = new ArrayList<>();
    }

    @Override
    public void addChannel(Channel channel) {
        channelList.add(channel);
    }

    @Override
    public void removeChannel(Channel channel) {
        channelList.remove(channel);
    }

    @Override
    public ChannelIterator iterator(ChannelTypeEnum type) {
        return new ChannelIteratorImpl(type, channelList);
    }

    private class ChannelIteratorImpl implements ChannelIterator {

        private ChannelTypeEnum typeEnum;
        private List<Channel> channels;
        private int position;

        public ChannelIteratorImpl(ChannelTypeEnum typeEnum, List<Channel> channels) {
            this.typeEnum = typeEnum;
            this.channels = channels;
        }

        @Override
        public boolean hasNext() {
            while (position < channels.size()) {
                Channel channel = channels.get(position);
                if (channel.getTYPE().equals(typeEnum)
                        || typeEnum.equals(ChannelTypeEnum.ALL)) {
                    return true;
                } else position++;
            }
            return false;
        }

        @Override
        public Channel next() {
            Channel channel = channels.get(position);
            position++;
            return channel;
        }
    }
}
