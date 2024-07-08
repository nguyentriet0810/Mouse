import speech_recognition as sr

sample_rate = 48000
chunk_size = 1024
r = sr.Recognizer()

mic_list = sr.Microphone.list_microphone_names()
print(mic_list)

for i, microphone_name in enumerate(mic_list):
    print("Device ID:", i, " - ", microphone_name)

device_id = 0
r.pause_threshold = 0.5  # in seconds
r.dynamic_energy_threshold = True

while True:
    print("Say something")
    errorRecog = 0
    with sr.Microphone(device_index=device_id, sample_rate=sample_rate, chunk_size=chunk_size) as source:
        r.adjust_for_ambient_noise(source)
        audio = r.listen(source, timeout=None)
    try:
        # Use recognize_google instead of recognize_google_cloud
        reg_text = r.recognize_google(audio, language="vi-VN")
        print(reg_text)
    except sr.UnknownValueError:
        print("Could not understand audio!")
    except sr.RequestError as e:
        print("Could not request results from Google service; {0}".format(e))
