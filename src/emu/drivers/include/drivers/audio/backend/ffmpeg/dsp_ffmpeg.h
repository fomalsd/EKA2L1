/*
 * Copyright (c) 2020 EKA2L1 Team.
 * 
 * This file is part of EKA2L1 project.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <drivers/audio/backend/dsp_shared.h>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include <vector>

namespace eka2l1::drivers {
    struct dsp_output_stream_ffmpeg : public dsp_output_stream_shared {
    protected:
        AVCodecContext *codec_;
        AVFormatContext *av_format_;
        AVIOContext *io_;

        std::uint8_t *custom_io_buffer_;
        std::uint64_t timestamp_in_base_;
        std::vector<std::uint8_t> queued_data_;

        enum state {
            STATE_NONE,
            STATE_FORMAT_OPENED,
            STATE_FRAME_READING
        } state_;

    protected:
        bool need_more_user_buffer() override;

    public:
        explicit dsp_output_stream_ffmpeg(drivers::audio_driver *aud);
        ~dsp_output_stream_ffmpeg() override;

        bool format(const four_cc fmt) override;

        void get_supported_formats(std::vector<four_cc> &cc_list) override;
        bool decode_data(dsp_buffer &original, std::vector<std::uint8_t> &dest) override;

        int read_queued_data(std::uint8_t *buffer, int buffer_size);
    };
}