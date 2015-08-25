package com.iheartradio.m3u8;

import java.util.ArrayList;
import java.util.List;

import com.iheartradio.m3u8.data.EncryptionData;
import com.iheartradio.m3u8.data.MediaPlaylist;
import com.iheartradio.m3u8.data.PlaylistType;
import com.iheartradio.m3u8.data.StartData;
import com.iheartradio.m3u8.data.TrackData;
import com.iheartradio.m3u8.data.TrackInfo;

class MediaParseState implements IParseState<MediaPlaylist> {
    public final List<TrackData> tracks = new ArrayList<TrackData>();
    public final List<String> unknownTags = new ArrayList<String>();

    public Integer targetDuration;
    public Integer mediaSequenceNumber;
    public Boolean isIframesOnly;
    public PlaylistType playlistType;
    public TrackInfo trackInfo;
    public EncryptionData encryptionData;
    public StartData startData;
    public boolean endOfList;

    @Override
    public MediaPlaylist buildPlaylist() throws ParseException {
        return new MediaPlaylist.Builder()
                .withTracks(tracks)
                .withUnknownTags(unknownTags)
                .withTargetDuration(targetDuration)
                .withIsIframesOnly(isIframesOnly == null ? false : true)
                .withStartData(startData)
                .withMediaSequenceNumber(mediaSequenceNumber == null ? 0 : mediaSequenceNumber)
                .withPlaylistType(playlistType)
                .build();
    }
}
