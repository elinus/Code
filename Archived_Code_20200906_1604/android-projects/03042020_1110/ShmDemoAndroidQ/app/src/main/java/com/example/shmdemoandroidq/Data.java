package com.example.shmdemoandroidq;

import android.os.Parcel;
import android.os.Parcelable;

public class Data implements Parcelable {

    private int position;
    private int limit;
    private int capacity;

    public Data(int position, int limit, int capacity) {
        this.position = position;
        this.limit = limit;
        this.capacity = capacity;
    }

    protected Data(Parcel in) {
        position = in.readInt();
        limit = in.readInt();
        capacity = in.readInt();
    }

    public static final Creator<Data> CREATOR = new Creator<Data>() {
        @Override
        public Data createFromParcel(Parcel in) {
            return new Data(in);
        }

        @Override
        public Data[] newArray(int size) {
            return new Data[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(position);
        dest.writeInt(limit);
        dest.writeInt(capacity);
    }
}
